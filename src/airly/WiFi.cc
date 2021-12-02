#include <airly/WiFi.h>

/* AVR low-level */
#include <avr/pgmspace.h>

/* Arduino */
#include <Arduino.h>
#include <ESP8266WebServer.h>

/* Config portal */
#include <WiFiManager.h>

/* Preprocessor-based localization */
#include <airly/I18n.h>

/* Utilities */
#include <airly/Util.h>

static const char* headElementsTemplate PROGMEM =
    "<script>document.title='{title}';</script>"
    "<link rel=\"icon\" type=\"image/png\""
    "href=\"data:image/"
    "png;base64,"
    "iVBORw0KGgoAAAANSUhEUgAAAQAAAAEACAAAAAB5Gfe6AAAK6UlEQVQYGe3BCViUZQIH8P8M"
    "IIiKuuaRWh5pme6adx5kt2utlNZari2Wj+I+a5tkrFn5WGRb6Vop+"
    "qxJp2lZbqkppml2iGSuB5Rl5ZU3pggKIscwM/9FJedgZr73+77xm2/g/"
    "f0gSZIkSZIkSZIkSZIkSZIkSZIkSZIkSZIkSZIkSZIkSZdQ/R5D7n9gWN8mqI2sN8/"
    "dySoH3hkWjdoldsJ+eih4vhlqkRFHWc2ZSVGoJRovo0/bOqBW6LiPfhTeilrgD8fpV/"
    "kw1HjtjjKAsptQw8VkM6CCNqjZ5lJBphU1WS87lYxBTbaRio7HouYaSAHJqLnep4DdqLHiSi"
    "iiD8yoTtvOXdvHQpe7KSQVZtNkzKI9FTzncMZjV0OzVyhkA8wlfrmN7r4ZGQFt1lPIKZhJ5/"
    "WsZted0OQgxTSDaVin2OjL+3HQoJhiroVZxK2lH3uugWoWJ8X0gUlctp1+"
    "negJ1WwUcx3MIXYTAzjZCWqdpJj2MAXLxwxob0OolE0h9jowhUeo4AOotJhCdsMUWp+"
    "hkgSoM4FC3oYpLKaivZFQpQuFJMIMrrJTWSLU2UEBpY1gBmkUsA3qpFDAYphB1HGK6AxV4gq"
    "orAfMYCCFPAF1plDRRzCFpylkHdSJ3kUFZ6+"
    "EKaygkDyo1KecgSXBHH6imCZQaQIDWgiTKKCYa6HWTAawrg5MwkYx10MtSyr9WtcAZlFOMb2"
    "g3rhS+"
    "uScFQnTOEkx10CD67bRh8MJMJHvKMTZABq0fSDlAL2cnlYPZvJfCjkKLSbRsX3lVjtdtiTHw"
    "VwmUchyaPE5z8nP+iRj0/c/bl3x0gMtYTo9KeQRaFC/nFWc2/"
    "51BczJ8gsFOK6ABnfTTReY1LMU8Dm0eJUuh2FWzUuo7A5osY8u6TCtWVT0vyG9oN61dDMMph"
    "WXSwWO8aVnboNqE+"
    "liawjzGupkYIuKyLKhUGstXb6Emc1mQDknWaniQahTt4Quk2FmER8ygAPHeJ5zAlT5E910ha"
    "nFLKNfuw+yivNxqDGXLrkWmFtEGv346nu6TLdA3B66vAHTG3acPpQ9t4nuXrVCVEe6+"
    "TPMr3FaGb04V3ZZS0+LoyBoAl3sv0M4uPyFQ3RT+FZ3xGXSS0ZdiFlNl0yECWu/"
    "p1bsKiZLD3428466qBS7ml42xEFEzFm6PIWwYomCS50l9LKtKQQMppseCGMRr9HLj62hbDZd"
    "jlmgU9SA8bM/yFj+3oujO8Nwln/Ty/"
    "4OULSLLgugS+RdHxXzomNze8Nok+"
    "nlWFcoaEc3I6BDxNh99LLhFhjs7w56KuiHwMbTxd4E2vXKpg9LmsNYI230VHw7AlpJl03Qbm"
    "I5fTp2K4w1pISeyu5BdVGdhj427eX09BlPPz5taT6rPA2tIubTH3sSjHVjIT3ZR8NDzKAXN1"
    "fQTVHWqhwHK/WGRpZF9M85DsbqlUdPzkfh0jMtjz4c/"
    "vj93DwrNJrJQOx3wVidj9DLdFxgTdhCf5yrhkGjBCcDOtUOxmq7h17mWFBp6M8M6JNO0KJZA"
    "RVkWmCsFjvo5Z1ItF9FJba0+lBvARWNgsEu20ovj40+SwG7u0OtTg4qOhQFg9X/"
    "jB42vEcxpeOh0lsUkAijRS+jm+"
    "1bKGyeFWrUO0MBX8JwEQt40a69VGF5DFQYSRGOVjCcZTarHDxKVTIiIe4tCklECEzmecf2UK"
    "VFFgjbRSHpCIXJTpL531K15yCqTgWFZCIk/"
    "uZg0RKq50yAkBZDOlDMEYTGiDNTndTgRCsoiItPXriTHEYxZxAiHU5QkzXwL6pn8sKdDp6XS"
    "jF2hMjr1Ohu+BLZZVRaVjld3qWYQoRGXwc1OlAXXtqPSssqoZdtFLMfobGOmk2AS8uE1Ix8+"
    "lJaSiHrEBK9qd3haJzT6LbUjOP07ycKmYWQWEYdxjaIT164kwrWU8hQhEIzG3X4ZhUFrKaIs"
    "oYIhYnUZS4F5ByjgKUIie3UZTEF2GZSwCCEQjMndcmmiMFnqWgrQuIv1Md+"
    "iEoKv5jR4VkquhkhkU6dNjEA286F47pYAcTspoKFCI1t1Gk9fbPvXJgcH43fdC1hQHsbIjQK"
    "qdOXrC43Y3J8LDyNcjKA010RGi2p1w4H3eVmpCY0gS8p9K/4JoRIP+pV8DOrnM6antAC/"
    "iXZ6Ufe9QiVQdTLvohkUVbaqC4WKBh4hD5taY+"
    "QuZe6jZyT2MkKIU1ed7CaoklRCJ1E6tYUKnT70EEPZ166HKF0H3WrD1VaTdpoY5XCjAfjEFp"
    "3Ui+HFWrV6/"
    "1AyjNTHr339xEIuRuoVxHCWjvqtRNhzVpKnZYjvP1AnWYgvL1LnUYivCVRp1YIbx2pz88Id3"
    "upSxrC3TTq0gfhriP12GNB2NtIHZ5E+BtC7QobIfxZsqnZC6gBmo6lVqeaIvx135+"
    "zlho9gvD317Pkx2XU5IdIhLvI6TznY2pR1hPhrukXPM/2NTWY+lYswlv/"
    "XFY5kUvVVu9hZj2Es3HlvOjbfKqU8wvJdTEIW9Gv093SYqryy0GeszYGYar1Znp6uYgq7DrE"
    "C9ZEIyzdfIJeShOPU1hOLn+"
    "zPAphaJyN3r5ueVUOBS3PpcvSSJhZh6Q3sw4UFBz97sOp8VG4IGYBq0mvA0SnOSmg5Jlcuvs"
    "wEmZVf8J2usmb0wmVrtxGb2VjcV7Cfipa33kfPS2ywpSin8ynF8eSdhicT2+"
    "HeqFK3WmlDOjQcKB/"
    "ET0tsMKE+u+mDyWPj6S3Dc3h0iz1FP3an1wXlQacoac3rTCdSRX07dN59JQeBQ+"
    "NJ26nL7aM4ZG44IZienrDAnOxzqFfP3xNN6UPorprp6wvoYfjS8Y1gcvtpfT0mgWm8goD+"
    "OUgLzrYE75F933ohQ8+2/x99sZPFzw1vLMFngaV0tMsmEkKA/"
    "quhFXWNIZGg8vo6RWYR18bA1vD85zTI6DZUBs9zYRZ1PmJCpzLWKnoXuhxTwU9paJS5PX/"
    "fHNj9r7szDdT+kQiNCZTUU4muasL9Blhp6ck9JiXT5e8/3RHCMTmUdlDRzIaQa/"
    "7Kuhu+y3r6G1NNxjuYQrIamOBfg866JL9hp3V2dPqwmBbKOJqBMNoB3+T/"
    "RN923E1DNWWQiYjKMY4ecG3J+lPfn8YaTSFrEVwJDl5Tk4x/"
    "SvqAQPNp5DTCJJkVtp8koH8eiWM8yXFtECQTCTXbmZgm6NgmL0U0xvBkrJ6GpVMhmGOU8wtC"
    "JqrSqikuDWMcpJi/"
    "oigSaeyOTDKAYrph2BpXkZlJU1gkC0U0wHB8ihFjIdB3qWQ8kgEyyaK+"
    "AoGSaGQ7QiWBhUUUR4LY/"
    "SikJkIllspZiCMYT1METciWB6mmCQYZAYFHLAiWGZQzPMwyJU2KpuEoJlHMXNglAVUlFcfQf"
    "MGxcyHUVqcppIkBM9sipkJw4yngkwrgmcqxTwBw1iWMaC81giiERRzD4wTu4kBlMQjmDpTTE"
    "cYqOm39KvkTgSV5VeKOAJDNVxPP04MQJAtoIh0GCviWTt9+"
    "aoVgu02ioiH0bplsZoTY6wIOuuPVLbDAuMN+sxBd/"
    "seq4dLIZHK7kdItE5ecYLnlWx+"
    "Md6CS8O6mUq2WBEyjbvdcGvPNlZcQj1tDKzsOtRsKQzsH6jhLG8zkNdQ40UupX9LIlDzRcyn"
    "P3OtqBVGn6UvxYmoLdqtZHXL26AWGfCJg+7sK/uhlmmd8mkxLyheM7ElaiNru5uHJw6/"
    "qa0VkiRJkiRJkiRJkiRJkiRJkiRJkiRJkiRJkiRJkiRJkiTm/"
    "5Bxv5BS7EiAAAAAAElFTkSuQmCC\" />"
    "<style>body{background-color:#305067;color:#fff}button{background:#"
    "597285;color:#fff}input{color:#000;text-align:left;"
    "background-color:#d2d9de;margin-bottom:0.5rem;}a{color:#fff;}</style>";

static String getAccessPointName() {
  auto macAddress = getMacAddressWithoutColon();
  macAddress.toUpperCase();

  auto ssid = String(i18n::DeviceTitle) + " ";
  ssid += macAddress.substring(macAddress.length() - 4);
  return ssid;
}

static String createHeadElements(const String& accessPointName) {
  auto headElements = String(headElementsTemplate);
  headElements.replace("{title}", accessPointName);
  return headElements;
}

void beginWiFi() {
  WiFiManager wifiManager;

  auto accessPointName = getAccessPointName();
  auto headElements = createHeadElements(accessPointName);

  wifiManager.setDebugOutput(false);
  wifiManager.setCustomHeadElement(headElements.c_str());
  wifiManager.autoConnect(getAccessPointName().c_str());
}
