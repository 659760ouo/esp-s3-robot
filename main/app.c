#include <stdio.h>
#include "cam.h"
#include "app_httpd.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"

#define WIFI_SSID "Tenda_wifi_2.4GHz"
#define WIFI_PASS "91297386"

static void wifi_init_sta(void)
{
    esp_netif_init();
    esp_event_loop_create_default();
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);

    wifi_config_t wifi_cfg = {
        .sta = {
            .ssid = WIFI_SSID,
            .password = WIFI_PASS,
        },
    };

    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_cfg);
    esp_wifi_start();
    esp_wifi_connect();
}

void app_main(void)
{
    nvs_flash_init();
    wifi_init_sta();

    camera_init();
    startCameraServer(); // ✅ NOW THIS WORKS!
}