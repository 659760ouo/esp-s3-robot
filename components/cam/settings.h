#pragma once



// Pin definition for CAMERA_MODEL_AI_THINKER
#define PWDN_GPIO_NUM     -1
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      15
#define SIOD_GPIO_NUM       4
#define SIOC_GPIO_NUM       5
#define VSYNC_GPIO_NUM      6
#define HREF_GPIO_NUM       7
#define PCLK_GPIO_NUM      13
#define Y2_GPIO_NUM        11
#define Y3_GPIO_NUM         9
#define Y4_GPIO_NUM         8
#define Y5_GPIO_NUM        10
#define Y6_GPIO_NUM        12
#define Y7_GPIO_NUM        18
#define Y8_GPIO_NUM        17
#define Y9_GPIO_NUM        16

//wifi settings
const char *sid = "Tenda_wifi_2.4GHz";
const char *password = "91297386";


// Function prototypes -- for camera image fetching and returning for camera server to upload
esp_err_t camera_init(void);
camera_fb_t* camera_get_frame(void);
void camera_return_frame(camera_fb_t* fb);