# LightAlign
LightAlign is a memory-efficient alignment tool for HiFi data that innovatively utilizes sequence fuzzy feature and reduces the peak memory usage during overlaps detection. It outputs Pairwise Alignment Format (PAF), when combined with miniasm, LightAlign enables high-quality bacterial genome assembly with memory usage below 1 GB, while also making eukaryotic genome assembly feasible on standard personal computers or even laptops.

## Installation
### windows system:
To use LightAlign, download all the source code to your computer, place it in the same project, compile it, and generate the executable (.exe) file to start using the tool; or you can also download LightAlign.exe to your computer.
### Linux system:
GCC/12.2.0  
```g++ -std=c++17 \   
    -isystem /public/home/software/opt/bio/software/GCC/12.2.0/include/c++/12.2.0 \  
    -ILightAlign/include \  
    LightAlign/src/help.cpp \  
    LightAlign/src/step4_5.cpp \  
    LightAlign/src/step3.cpp \  
    LightAlign/src/step2.cpp \  
    LightAlign/src/step1.cpp \  
    LightAlign/src/functions.cpp \  
    LightAlign/src/MurmurHash3.cpp \  
    LightAlign/src/preprocess_fasta.cpp \  
    -o LightAlign_executable \  
    -pthread \  
    -lstdc++fs  
```
## Tutorial
LightAlign Basic Usage:  
LightAlign.exe -O [Output path for results and intermediate files] -i [Input file path, FASTA/FASTQ]

LightAlign Detailed Usage:  
-h Show help documentation  
-p Required when processing FASTA files containing internal line breaks within sequences  
-O Output file path  
-i Input file path  
-w INT Window size [30]  
-l INT Alignment unit length/minimum overlap length. Recommended 800-900 for prokaryotes, 1000-1100 for eukaryotes [810]  
-e FLOAT Maximum error rate [0.02]  
-g INT Number of reads per group in the group alignment phase. Reducing this value decreases memory usage (current memory usage is consistently <1GB for prokaryotic datasets). Keep default unless specifically requiring ultra-low memory [10200]  
-d INT DBA. Can be adjusted to around 80 when average HiFi read length <10k [87]  
## Notes:
The executable may be flagged as virus - simply trust/allow the file.  
LightAlign executes in 5 steps. Upon completion, "All steps done." will be displayed. The final output is the PAF file in the output path.

## Limitations

## Contact
