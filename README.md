# huffman

C++로 구현한 허프만 코딩(Huffman Coding) 압축 알고리즘.

## 기능

- 문자 빈도 기반 허프만 트리 생성
- 텍스트 인코딩(압축) 및 디코딩(복원)
- Visual Studio 프로젝트 포함 (`.vcxproj`)

## 파일

```
main.cpp          # 진입점
huffman.cpp/.h    # 허프만 알고리즘 구현
```

## 빌드

Visual Studio에서 `huffman.vcxproj`를 열어 빌드하거나:

```bash
g++ -o huffman main.cpp huffman.cpp
```