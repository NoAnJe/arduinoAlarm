class clockCount {
  private:
  int minute;
  int hour;
  int sec;
  boolean is24hourMode;

  public:
  clockCount();
  addHour();
  subHour();
  addMin();
  subMin();
  addSec();
  subSec();
  set12hr();
  set24hr();
  String getStr();
}
