#pragma once

#include <Arduino.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

extern String page;

void get_login_page() {
  page = F("<!doctype html>");
  page += F("<html lang='en' data-bs-theme='dark'>");
  page += F("<head>");
  page += F("<title>PedalinoMini&trade;</title>");
  page += F("<meta charset='utf-8'>");
  page += F(" <meta name='viewport' content='width=device-width, initial-scale=1, shrink-to-fit=no'>");
  page += F("<link href='https://cdn.jsdelivr.net/npm/bootstrap@latest/dist/css/bootstrap.min.css' rel='stylesheet' crossorigin='anonymous'>");
  page += F("</head>");

  page += F("<body>");

  page += F("<div class='col-4'>");
  page += F("</div>");

  page += F("<div class='col-4'>");
  page += F("<form class='form-signin'>");
  page += F("<div class='text-center mb-4'>");
  page += F("<img class='mb-4' src='/logo.png' alt='' width='64' height='64'>");
  page += F("<h1 class='h3 mb-3 font-weight-normal'>PedalinoMini&trade;</h1>");
  page += F("<p>Wireless MIDI foot controller <a href='https://github.com/fuegovic/PedalinoMini/blob/single/docs/CHANGELOG.md'>More info</a></p>");
  page += F("</div>");

  page += F("<div class='form-label-group'>");
  page += F("<input type='text' id='username' class='form-control' placeholder='Username' required='' autofocus=''>");
  page += F("<label for='username'>Username</label>");
  page += F("</div>");

  page += F("<div class='form-label-group'>");
  page += F("<input type='password' id='password' class='form-control' placeholder='Password' required=''>");
  page += F("<label for='password'>Password</label>");
  page += F("</div>");

  page += F("<div class='checkbox mb-3'>");
  page += F("<label>");
  page += F("<input type='checkbox' value='remember-me'> Remember me");
  page += F("</label>");
  page += F("</div>");
  page += F("<button class='btn btn-lg btn-primary btn-block' type='submit'>Sign in</button>");
  page += F("<p class='mt-5 mb-3 text-muted text-center'>© 2018-2019</p>");
  page += F("</form>");
  page += F("</div>");

  page += F("<div class='col-4'>");
  page += F("</div>");

  page += F("<script src='https://cdn.jsdelivr.net/npm/bootstrap@latest/dist/js/bootstrap.bundle.min.js' crossorigin='anonymous'></script>");
  page += F("</body>");
  page += F("</html>");
}
