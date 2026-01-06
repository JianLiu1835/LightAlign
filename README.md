# LightAlign
LightAlign is a memory-efficient alignment tool for HiFi data that utilizes sequence fuzzy feature and reduces the peak memory usage during overlaps detection. It outputs Pairwise Alignment Format (PAF), when combined with miniasm, LightAlign enables high-quality bacterial genome assembly with memory usage below 1 GB, while also making eukaryotic genome assembly feasible on standard personal computers or even laptops.  
LightAlign is fully compliant with the C++17 language standard.  

## System Requirements
The following requirements reflect the environments where this software has been successfully tested. Other configurations with similar specifications may also work but are not officially verified:  
#### Operating System
* **64-bit** systems only
* **Windows**: Windows 10 version / Windows 11
* **Linux**: 
    * **Supported Distributions**:
        * **CentOS/RHEL 7.0+** (Tested on CentOS 7 with kernel 3.10.0-862.el7.x86_64)
        * **Ubuntu 18.04 LTS+** or **Ubuntu 20.04 LTS+** (Recommended)
        * Other distributions with **kernel 3.10.0+** and **glibc 2.17+** may work but are not officially tested
    * **Kernel**: Linux kernel 3.10.0+ (For CentOS/RHEL 7 series) or 4.15+ (For Ubuntu 18.04+)

#### Compiler (with full C++17 support)
* **Linux**: 
    * **GCC 7.5+** (Minimum required for full C++17 support)
    * **GCC 12.2.0+** (Recommended for better performance and newer features)
    * *Note: CentOS 7 default GCC is 4.8.5, which does NOT support C++17. You must install a newer version via devtoolset or compile from source.*
* **Windows**: 
    * **MSVC 19.30+** (Visual Studio 2022, Recommended)

#### Hardware
* **CPU**: 
    * **Minimum**: x86-64 processor with SSE4.2 support
    * **Recommended**: Modern x86-64 processor (AMD Ryzen 5 / Intel Core i5 equivalent or higher)
    * **Tested configurations**:
        * Development: AMD Ryzen 5 3600 6-Core Processor
        * Server/Production: AMD EPYC 7713 64-Core Processor
* **RAM**:
    * **Minimum**: 4 GB
    * **Recommended**: 8 GB or more for optimal performance
    * **Large-scale processing**: 16 GB+ recommended
* **Storage**: 500 MB free space for software and dependencies

### Tested Environments
This project has been actively developed and tested on the following configurations:
* **Development Machine**:
    * **CPU**: AMD Ryzen 5 3600 6-Core Processor
    * **OS**: Windows 10
* **High-Performance/Server Environment**:
    * **CPU**: AMD EPYC 7713 64-Core Processor
    * **OS**: Linux

## Installation
### windows system:
To use LightAlign, download all the source code to your computer, place it in the same project, compile this project using a C++ IDE such as Visual Studio, and generate the executable (.exe) file to start using the tool; or you can also download LightAlign.exe to your computer.
### Linux system:
One Compilation Example Using GCC 12.2.0:  
```
g++ -std=c++17 \  
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
### LightAlign Basic Usage:  
```LightAlign.exe -O [Output path for results and intermediate files] -i [Input file path, FASTA/FASTQ]```

### LightAlign Detailed Usage

LightAlign accepts the following command-line options:  

| Option | Type    | Description | Default |
|--------|---------|-------------|---------|
| `-h`   | flag    | Show help documentation and exit. | |
| `-i`   | string  | Path to the input file (required). | |
| `-O`   | string  | Path for the output file (required). | |
| `-w`   | INT     | Window size for alignment. | 30 |
| `-l`   | INT     | Alignment unit length / minimum overlap length. Recommended: 800–900 for prokaryotes, 1000–1100 for eukaryotes. | 810 |
| `-e`   | FLOAT   | Maximum allowed error rate for alignments. | 0.02 |
| `-g`   | INT     | Number of reads per group in the group alignment phase. Reducing this value lowers memory usage (current memory usage is consistently <1 GB for prokaryotic datasets). Keep default unless ultra-low memory is required. | 10200 |
| `-d`   | INT     | DBA (Dynamic Bandwidth Adjustment). Adjust to around 80 when average HiFi read length is <10 kb. | 87 |  
## Notes
LightAlign executes in 5 steps. Upon completion, "All steps done." will be displayed. The final output is the PAF file in the output path.
In tests conducted so far, LightAlign consumes the same amount of memory and has roughly the same runtime on both Linux and Windows.  

## Limitations
Currently, LightAlign is limited to the assembly of HiFi reads.
Despite its extremely low RAW usage, LightAlign is slower than current tools like minimap2.
## Contact
For any questions or suggestions, please reach out to liujian_HZAU@outlook.com.
