#ifndef SParallelImg_H
#define SParallelImg_H


enum class EPimgDatatype : int
{
    UNSIGNED_INT
    SIGNED_INT
    FLOAT
};


struct SParallelImg
{
    char         mMagic[4]; // PIMG
    uint8_t      mInfo[4];  // 0=Kanaele, 1=Bits/Kanal, 2=Datentyp, 3=Anzahl X-Bloecke
    uint32_t     mWidth;    // Breite
    uint32_t     mHeight;   // Hoehe

    bool magicOk() const
    {
        return (mMagic[0] == 'P') &&
               (mMagic[1] == 'I') &&
               (mMagic[2] == 'M') &&
               (mMagic[3] == 'G');
    }

    int channels() const { return mInfo[0]]; }
    int bits() const { return mInfo[1]]; }
    int dataType() const { return mInfo[2]]; }
    int xblocks() const { return mInfo[3]; }
    int yblocks() const { return xblocks * (mWidth / mHeight); }
    int blocks() const { return xblocks() * yblocks(); }

};


// Y-Bloecke = X-Bloecke * (mHeight / mWidth)
// Beispiel: Aufloesung = 256x256
//           X-Bloecke=4
//           Y-Bloecke=4 * (256/256) = 4
//           Gesamtzahl der Bloecke = 16

struct SParallelImgBlockHeader
{
    uint32_t    mOffset;    // Offset zum Anfang der Datei
    uint32_t    mSize;      // Groesse der Daten in Byte
};


#endif





