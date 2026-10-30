#include <stdio.h>


 typedef struct _IMAGE_DOS_HEADER {
      char e_magic[2];
      char e_cblp[2];
      char e_cp[2];
      char e_crlc[2];
      char e_cparhdr[2];
      char e_minalloc[2];
      char e_maxalloc[2];
      char e_ss[2];
      char e_sp[2];
      char e_csum[2];
      char e_ip[2];
      char e_cs[2];
      char e_lfarlc[2];
      char e_ovno[2];
      char e_res[4][2];
      char e_oemid[2];
      char e_oeminfo[2];
      char e_res2[10][2];
      char e_lfanew[4];
} IMAGE_DOS_HEADER;

typedef struct _IMAGE_DATA_DIRECTORY {
    char VirtualAddress[4];
    char Size[4];
} IMAGE_DATA_DIRECTORY;
typedef struct _IMAGE_NT_HEADER{
    char signature[4];
    
    /** Image file header**/
    char Machine[2];
    char NumberOfSections[2];
    char TimeDateStamp[4];
    char PointerToSymbolTable[4];
    char NumberOfSymbols[4];
    char SizeOfOptionalHeader[2];
    char Characteristics[2];


    /** Image optional header **/

    char Magic[2];
    char MajorLinkerVersion;
    char MinorLinkerVersion;
    char SizeOfCode[4];
    char SizeOfInitializedData[4];
    char SizeOfUninitializedData[4];
    char AddressOfEntryPoint[4];
    char BaseOfCode[4];
    char ImageBase[8];
    char SectionAlignment[4];
    char FileAlignment[4];
    char MajorOperatingSystemVersion[2];
    char MinorOperatingSystemVersion[2];
    char MajorImageVersion[2];
    char MinorImageVersion[2];
    char MajorSubsystemVersion[2];
    char MinorSubsystemVersion[2];
    char Win32VersionValue[4];
    char SizeOfImage[4];
    char SizeOfHeaders[4];
    char CheckSum[4];
    char Subsystem[2];
    char DllCharacteristics[2];
    char SizeOfStackReserve[8];
    char SizeOfStackCommit[8];
    char SizeOfHeapReserve[8];
    char SizeOfHeapCommit[8];
    char LoaderFlags[4];
    char NumberOfRvaAndSizes[4];
    IMAGE_DATA_DIRECTORY DataDirectory[16];

} IMAGE_NT_HEADER;

char exefile[] = "whoami.exe";
int main(){
    
    char f,s;
    IMAGE_DOS_HEADER dos_header;
    
    printf("opening file %s...\n", exefile);
    void *fhandle = fopen(exefile, "rb");

    if(fhandle==NULL){
        goto jmp_error;
    }


    if(fread(&dos_header, sizeof(IMAGE_DOS_HEADER), 1, fhandle)!=1){
        printf("Unable to read DOS_HEADER struct\n");
        goto jmp_error;
    }


    printf("%c%c\n", dos_header.e_magic[0], dos_header.e_magic[1]);
    

    jmp_error:
    if(fhandle == NULL) fclose(fhandle);
    
    return 0;
}
