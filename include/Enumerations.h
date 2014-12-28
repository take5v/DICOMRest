#ifndef ENUMERATIONS_INCLUDED
#define ENUMERATIONS_INCLUDED

enum HttpMethod
{
    HttpMethod_Get = 0,
    HttpMethod_Post = 1,
    HttpMethod_Delete = 2,
    HttpMethod_Put = 3
};

enum StoreStatus
{
    StoreStatus_Success,
    StoreStatus_AlreadyStored,
    StoreStatus_Failure
};

enum ResourceType
{
    ResourceType_Patient = 1,
    ResourceType_Study = 2,
    ResourceType_Series = 3,
    ResourceType_Instance = 4
};

enum Encoding
{
    Encoding_Ascii,
    Encoding_Utf8,
    Encoding_Latin1,
    Encoding_Latin2,
    Encoding_Latin3,
    Encoding_Latin4,
    Encoding_Latin5,                        // Turkish
    Encoding_Cyrillic,
    Encoding_Arabic,
    Encoding_Greek,
    Encoding_Hebrew,
    Encoding_Thai,                          // TIS 620-2533
    Encoding_Japanese,                      // JIS X 0201 (Shift JIS): Katakana
    Encoding_Chinese                        // GB18030 - Chinese simplified
    //Encoding_JapaneseKanji,               // Multibyte - JIS X 0208: Kanji
    //Encoding_JapaneseSupplementaryKanji,  // Multibyte - JIS X 0212: Supplementary Kanji set
    //Encoding_Korean,                      // Multibyte - KS X 1001: Hangul and Hanja
};

#endif // ENUMERATIONS_INCLUDED
