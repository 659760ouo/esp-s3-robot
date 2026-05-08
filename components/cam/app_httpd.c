#include "esp_camera.h"
#include "esp_http_server.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "nvs_flash.h"
#include "settings.h" // to use the camera settings and camera get functions

static const char *TAG = "webserver";

static esp_err_t jpg_stream_handler(httpd_req_t *req)
{
    httpd_resp_set_type(req, "multipart/x-mixed-replace; boundary=frame");

    while (1) {
        camera_fb_t *fb = camera_get_frame();
        if (!fb) {
            ESP_LOGE(TAG, "FeedBack failed");
            continue;
        }

        httpd_resp_send_chunk(req, "--frame\r\nContent-Type: image/jpeg\r\n\r\n", 44);  // 44 means the length of the string to send to connection, \r\n is return a new line, --frame is the boundary to separate each frame, content-type is the type of data we are sending to connection
        httpd_resp_send_chunk(req, (char *)fb->buf, fb->len); // send the image data to connection, fb->buf is the pointer to the pixel data, fb->len is the length of the buffer in bytes
        httpd_resp_send_chunk(req, "\r\n", 2);

        camera_return_frame(fb); // return the frame buffer back to the driver after sending it to connection, to free up memory for the next frame
    }

    return ESP_OK;
}

static const httpd_uri_t stream_uri = {
    .uri = "/",
    .method = HTTP_GET,
    .handler = jpg_stream_handler,
};

void startCameraServer(void)
{
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    httpd_handle_t server = NULL;

    if (httpd_start(&server, &config) == ESP_OK) {
        httpd_register_uri_handler(server, &stream_uri);
        ESP_LOGI(TAG, "Web server running: http://IP/");
    }
}