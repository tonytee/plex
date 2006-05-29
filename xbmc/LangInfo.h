#pragma once

class CLangInfo
{
public:
  CLangInfo();
  virtual ~CLangInfo();

  bool Load(const CStdString& strFileName);

  CStdString GetGuiCharSet() const;
  CStdString GetSubtitleCharSet() const;

  const CStdString& GetDVDMenuLanguage() const;
  const CStdString& GetDVDAudioLanguage() const;
  const CStdString& GetDVDSubtitleLanguage() const;

  bool ForceUnicodeFont() { return m_forceUnicodeFont; }

  const CStdString& GetDateFormat(bool bLongDate=false) const;
  
  typedef enum _MERIDIEM_SYMBOL
  {
    MERIDIEM_SYMBOL_PM=0,
    MERIDIEM_SYMBOL_AM,
    MERIDIEM_SYMBOL_MAX
  } MERIDIEM_SYMBOL;

  const CStdString& GetTimeFormat() const;
  const CStdString& GetMeridiemSymbol(MERIDIEM_SYMBOL symbol) const;

  typedef enum _TEMP_UNIT
  {
    TEMP_UNIT_FAHRENHEIT=0,
    TEMP_UNIT_KELVIN,
    TEMP_UNIT_CELSIUS,
    TEMP_UNIT_REAUMUR,
    TEMP_UNIT_RANKINE,
    TEMP_UNIT_ROMER,
    TEMP_UNIT_DELISLE,
    TEMP_UNIT_NEWTON
  } TEMP_UNIT;

  const CStdString& GetTempUnitString();
  CLangInfo::TEMP_UNIT GetTempUnit();
  

  typedef enum _SPEED_UNIT
  {
    SPEED_UNIT_KMH=0,
    SPEED_UNIT_MPH,
    SPEED_UNIT_MPS
  } SPEED_UNIT;

  const CStdString& GetSpeedUnitString();
  CLangInfo::SPEED_UNIT GetSpeedUnit();

  void GetRegionNames(CStdStringArray& array);
  void SetCurrentRegion(const CStdString& strName);
  const CStdString& GetCurrentRegion();

protected:
  void Clear();

protected:
  CStdString m_strGuiCharSet;
  CStdString m_strSubtitleCharSet;
  CStdString m_strDVDMenuLanguage;
  CStdString m_strDVDAudioLanguage;
  CStdString m_strDVDSubtitleLanguage;
  bool m_forceUnicodeFont;

  class CRegion
  {
  public:
    CRegion();
    virtual ~CRegion();
    void SetTempUnit(const CStdString& strUnit);
    void SetSpeedUnit(const CStdString& strUnit);
    CStdString m_strName;
    CStdString m_strDateFormatLong;
    CStdString m_strDateFormatShort;
    CStdString m_strTimeFormat;
    CStdString m_strMeridiemSymbols[MERIDIEM_SYMBOL_MAX];
    TEMP_UNIT m_tempUnit;
    SPEED_UNIT m_speedUnit;
  };

  typedef map<CStdString, CRegion> MAPREGIONS;
  typedef map<CStdString, CRegion>::iterator ITMAPREGIONS;
  typedef pair<CStdString, CRegion> PAIR_REGIONS;
  MAPREGIONS m_regions;
  CRegion* m_currentRegion; // points to the current region
  CRegion m_defaultRegion; // default, will be used if no region available via langinfo.xml
};


extern CLangInfo g_langInfo;
