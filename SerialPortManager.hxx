//=========================================================================
//
//  H   H    A    RRRR   M   M   OOO   N   N  Y   Y
//  H   H   A A   R   R  MM MM  O   O  NN  N   Y Y
//  HHHHH  AAAAA  RRRR   M M M  O   O  N N N    Y   "Harmony Cart software"
//  H   H  A   A  R R    M   M  O   O  N  NN    Y
//  H   H  A   A  R  R   M   M   OOO   N   N    Y
//
// Copyright (c) 2009-2017 by Stephen Anthony <sa666666@gmail.com>
//
// See the file "License.txt" for information on usage and redistribution
// of this file, and for a DISCLAIMER OF ALL WARRANTIES.
//=========================================================================

#ifndef __SERIALPORTMANAGER_HXX
#define __SERIALPORTMANAGER_HXX

#include "Cart.hxx"

#if defined(BSPF_WINDOWS)
  #include "SerialPortWindows.hxx"
#elif defined(BSPF_MACOS)
  #include "SerialPortMACOSX.hxx"
#elif defined(BSPF_UNIX)
  #include "SerialPortUNIX.hxx"
#else
  #error Unsupported platform!
#endif

class SerialPortManager
{
  public:
    SerialPortManager();
    ~SerialPortManager() = default;

    void setDefaultPort(const string& port);
    void connectHarmonyCart(Cart& cart);
    bool harmonyCartAvailable();

    SerialPort& port();
    const string& portName();
    const string& versionID();

    bool openCartPort();
    void closeCartPort();

  private:
    bool detect(const string& device, Cart& cart);

  private:
  #if defined(BSPF_WINDOWS)
    SerialPortWindows myPort;
  #elif defined(BSPF_MACOS)
    SerialPortMACOSX myPort;
  #elif defined(BSPF_UNIX)
    SerialPortUNIX myPort;
  #endif

    bool myFoundHarmonyCart;
    string myPortName;
    string myVersionID;

  private:
    // Following constructors and assignment operators not supported
    SerialPortManager(const SerialPortManager&) = delete;
    SerialPortManager(SerialPortManager&&) = delete;
    SerialPortManager& operator=(const SerialPortManager&) = delete;
    SerialPortManager& operator=(SerialPortManager&&) = delete;
};

#endif // __SERIALPORTMANAGER_HXX
