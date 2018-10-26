/**
 * Declare the starting time to be 00:00:00 in 24 hour format
 */
clockCount::clockCount() {
  hour = 0;
  minute = 0;
  sec = 0;
  is24hourMode = true;
}

/**
 * Add an hour
 */
clockCount::addHour() {
  if(hour == 23) {
    hour = 0;
  }
  else {
    hour++;
  }
}

/**
 * Subtract an hour
 */
clockCount::subHour() {
  if(hour == 0) {
    hour = 23;
  }
  else {
    hour--;
  }
}

/**
 * Add a minute
 */
clockCount::addMin() {
  if(minute == 59) {
    minute = 0;
    subHour();
  }
  else {
    minute++;
  }
}

/**
 * Subtract a minute
 */
clockCount::subMin() {
  if(minute == 0) {
    minute = 59;
    addHour();
  }
  else {
    minute--;
  }
}

/**
 * Add a second
 */
clockCount::addSec(){
  if(sec == 59) {
    sec = 0;
    addMin();
  }
  else {
    sec++;
  }
}

/**
 * Subtract a second
 */
clockCount::subSec(){
  if(sec == 0) {
    sec = 59;
    subMin();
  }
  else {
    sec--;
  }
}

/**
 * Set to 12 Hour Mode
 */
clockCount::set12hr() {
  is24hourMode = false;
}

/**
 * Set to 24 Hour Mode
 */
clockCount::set24hr() {
  is24hourMode = true;
}

/**
 * This returns the current time in the format HH:MM:SS AM
 */
String clockCount::getString() {
  int tempHour = 0;
  String 24hour = "  ";
  if(!is24hourMode && (hour > 12)) {
    tempHour = hour - 12;
    24hour = "PM";
  }
  else if(!is24hourMode && (hour == 0)) {
    tempHour = 12;
    24hour = "AM";
  }
  else if(!is24hourMode && (hour == 12)) {
    tempHour = 12;
    24hour = "PM";
  }
  else if(!is24hourMode) {
    tempHour = hour;
    24hour = "AM";
  }
  else {
    tempHour = hour;
  }

  String minFormat = "";
  if(minute < 10) {
    minFormat = "0" + minute;
  }
  else {
    minFormat = minute;
  }

  String secFormat = "";
  if(sec < 10) {
    secFormat = "0" + sec;
  }
  else {
    secFormat = sec;
  }

  String formattedTime = hour + ":" + minFormat + ":" + secFormat + " " + 24hour;
  return formattedTime;
}
