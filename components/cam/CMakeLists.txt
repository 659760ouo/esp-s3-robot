idf_component_register(
    SRCS "app_httpd.c" "cam.c"
    INCLUDE_DIRS "."
    REQUIRES esp32-camera esp_log 
)

idf_component_register(
    SRCS "app_httpd.c"
    INCLUDE_DIRS "."
    REQUIRES esp32-camera esp_wifi nvs_flash esp_http_server
)