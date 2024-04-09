#include "ManchesterEncoding.h"

void printArrayData(unsigned char* data, unsigned int lenArr, enum StatusMessages status)
{
    if (status == OK)
    {
        for (int i=0; i<lenArr; i++)
            printf("%02X ",data[i]);
    }
    else if (status == ERROR_STANDARD)
        printf("\nInvalid conversion standard.\n");
    else if (status == INVALID_ENCODE)
        printf("\nInvalid encoded data.\n");
    else if (status == ERROR_SIZE)
        printf("\nInvalid array size. size must be multiple of 2\n");
}

int main()
{
    enum StatusMessages status;
    enum ConversionStandard standard;
    standard = THOMAS;

    unsigned char data[] = {0xDE, 0xAD, 0xBE, 0xEF, 0x01, 0x90}; // PUT YOUR INPUT DATA HERE
    unsigned char encodedData[ARRAY_LENGTH(data)*2];
    unsigned char decodedData[ARRAY_LENGTH(data)];

    // Example using encoding and then decoding:
    printf("Original data:\n");
    for (int i=0; i<ARRAY_LENGTH(data); i++)
        printf("%02X ",data[i]);

    status = encodeManchester(data, ARRAY_LENGTH(data), encodedData, standard);
    printf("\nEncoded data:\n");
    printArrayData(encodedData, ARRAY_LENGTH(encodedData), status);
    if(status == OK) // in order to decode must check if encode succeded
    {
        status = decodeManchester(encodedData, ARRAY_LENGTH(encodedData), decodedData, standard);
        printf("\nDecoded data:\n");
        printArrayData(decodedData, ARRAY_LENGTH(decodedData), status);
    }
    
    printf("\n\nFaulty Examples:");
    // Example getting encoded data in wrong size
    unsigned char encodedDataFaultShort[] = {0xA6, 0xA9, 0x99};
    unsigned char decodedDataFaultShort[ARRAY_LENGTH(encodedDataFaultShort)/2];
    status = decodeManchester(encodedDataFaultShort, ARRAY_LENGTH(encodedDataFaultShort), decodedDataFaultShort, standard);
    printf("\nDecoded data:\n");
    printArrayData(decodedDataFaultShort, ARRAY_LENGTH(decodedDataFaultShort), status);

    // Example getting encoded data with error in some bits
    unsigned char encodedDataFaultEncode[] = {0xA6, 0xA9, 0x99, 0xA7};
    unsigned char decodedDataFaultEncode[ARRAY_LENGTH(encodedDataFaultEncode)/2];
    status = decodeManchester(encodedDataFaultEncode, ARRAY_LENGTH(encodedDataFaultEncode), decodedDataFaultEncode, standard);
    printf("\nDecoded data:\n");
    printArrayData(decodedDataFaultShort, ARRAY_LENGTH(decodedDataFaultShort), status);

    return 0;
}