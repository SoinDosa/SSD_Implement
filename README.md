# SSD_Implement
데이터 저장장치인 SSD의 시스템을 SW로 구현한 코드입니다.<br>
한 단위가 4byte인 LBA(Logical Block Address)를 사용하며 LBA의 범위는 0~99 입니다.<br>
다만 저장되는 Data(`nand.txt`, `result.txt`)는 실제 400byte가 아니고 4byte 값을 나타내는 `10자리 string 100개`의 집합입니다.

### SSD/main.c
| `int main(int, char*[])`
* argv[0] ~ argv[3]을 입력받아 데이터의 쓰기, 읽기를 수행합니다
### SSD/write.c
| `void W(int, char*)`
* 입력받은 LBA 주소에 값을 입력합니다.
* `nand.txt` 파일이 수정됩니다.
### SSD/read.c
| `void R(int)`
* 입력받은 LBA 주소의 값을 가져옵니다.
* 가져온 값은 `result.txt`에 저장됩니다.
### TestShell.c
* 해당 SSD 프로그램을 테스트하는 Shell입니다
* 기능검증을 위한 `void testapp1()`, `void testapp2()` 함수가 존재합니다.
