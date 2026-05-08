idf_component_register(
    SRCS "app.c"
    INCLUDE_DIRS "."
    REQUIRES cam esp32-camera esp_wifi nvs_flash esp_http_server
)