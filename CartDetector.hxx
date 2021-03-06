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

#ifndef __CART_DETECTOR_HXX
#define __CART_DETECTOR_HXX

#include "bspf.hxx"
#include "BSType.hxx"

/**
  Auto-detect cart type.
  Based on auto-detection code from Stella (https://stella-emu.github.io)

  @author  Stephen Anthony
*/
class CartDetector
{
  public:
    /**
      Try to auto-detect the bankswitching type of the cartridge,
      based first on filename, then on actual file content

      @param rom    The file containing the ROM image
      @param image  A pointer to the ROM image (may be null)
      @param size   The size of the ROM image (may be 0)
      @return  The "best guess" for the cartridge type
    */
    static BSType autodetectType(const string& rom, const BytePtr& image, uInt32 size);
    static BSType autodetectType(const string& rom);

  private:
    /**
      Try to auto-detect the bankswitching type of the cartridge
      based on the filename extensions as defined in the Harmony
      manual

      @param rom  The file containing the ROM image
      @return  The "best guess" for the cartridge type
    */
    static BSType autodetectTypeByExtension(const string& rom);

    /**
      Try to auto-detect the bankswitching type of the cartridge
      based on an analysis of the ROM data (from Stella)

      @param rom  The file containing the ROM image
      @return  The "best guess" for the cartridge type
    */
    static BSType autodetectTypeByContent(const BytePtr& image, uInt32 size);

    /**
      Search the image for the specified byte signature

      @param image      A pointer to the ROM image
      @param imagesize  The size of the ROM image
      @param signature  The byte sequence to search for
      @param sigsize    The number of bytes in the signature
      @param minhits    The minimum number of times a signature is to be found

      @return  True if the signature was found at least 'minhits' time, else false
    */
    static bool searchForBytes(const uInt8* image, uInt32 imagesize,
                               const uInt8* signature, uInt32 sigsize,
                               uInt32 minhits);

    /**
      Returns true if the image is probably a SuperChip (128 bytes RAM)
      Note: should be called only on ROMs with size multiple of 4K
    */
    static bool isProbablySC(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a 4K SuperChip (128 bytes RAM)
    */
    static bool isProbably4KSC(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image probably contains ARM code in the first 1K
    */
    static bool isProbablyARM(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a 0840 bankswitching cartridge
    */
    static bool isProbably0840(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a 3E bankswitching cartridge
    */
    static bool isProbably3E(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a 3E+ bankswitching cartridge
    */
    static bool isProbably3EPlus(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a 3F bankswitching cartridge
    */
    static bool isProbably3F(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a 4A50 bankswitching cartridge
    */
    static bool isProbably4A50(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a BF/BFSC bankswitching cartridge
    */
    static bool isProbablyBF(const BytePtr& image, uInt32 size, BSType& type);

    /**
      Returns true if the image is probably a BUS bankswitching cartridge
    */
    static bool isProbablyBUS(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a CDF bankswitching cartridge
    */
    static bool isProbablyCDF(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a CTY bankswitching cartridge
    */
    static bool isProbablyCTY(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a CV bankswitching cartridge
    */
    static bool isProbablyCV(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a CV+ bankswitching cartridge
    */
    static bool isProbablyCVPlus(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a DASH bankswitching cartridge
    */
    static bool isProbablyDASH(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a DF/DFSC bankswitching cartridge
    */
    static bool isProbablyDF(const BytePtr& image, uInt32 size, BSType& type);

    /**
      Returns true if the image is probably a DPC+ bankswitching cartridge
    */
    static bool isProbablyDPCplus(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a E0 bankswitching cartridge
    */
    static bool isProbablyE0(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a E7 bankswitching cartridge
    */
    static bool isProbablyE7(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably an EF/EFSC bankswitching cartridge
    */
    static bool isProbablyEF(const BytePtr& image, uInt32 size, BSType& type);

    /**
      Returns true if the image is probably an F6 bankswitching cartridge
    */
    static bool isProbablyF6(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably an FA2 bankswitching cartridge
    */
    static bool isProbablyFA2(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably an FE bankswitching cartridge
    */
    static bool isProbablyFE(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a MDM bankswitching cartridge
    */
    static bool isProbablyMDM(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a SB bankswitching cartridge
    */
    static bool isProbablySB(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably a UA bankswitching cartridge
    */
    static bool isProbablyUA(const BytePtr& image, uInt32 size);

    /**
      Returns true if the image is probably an X07 bankswitching cartridge
    */
    static bool isProbablyX07(const BytePtr& image, uInt32 size);

  private:
    // Following constructors and assignment operators not supported
    CartDetector() = delete;
    CartDetector(const CartDetector&) = delete;
    CartDetector(CartDetector&&) = delete;
    CartDetector& operator=(const CartDetector&) = delete;
    CartDetector& operator=(CartDetector&&) = delete;
};

#endif
