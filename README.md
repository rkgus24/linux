**디렉토리와 파일 관련 명령어**
✨ ls
현재 디택토리의 파일 목록을 출력하는 명령어

✨ pwd
현재 위치하고 있는 디렉토리를 알려주는 명령어

✨ mkdir
새로 생성할 디렉토리명

✨ cd
cd 이동할 디텍토리의 경로명

✨ rm
rm 파일명
rm-r 디텍토리명
--help/man // 명령어 뒤에 --help/ man를 붙이면 명령의 사용설명서가 출력됨

ex)
ls--help
rm--help
mkdir--help
pwd--help

man 매뉴얼 사용법
q키 - 나가기
h키 - man 사용법 확인
화살표키, 엔터키 - 한줄씩 넘기기
스페이스바 - 한 페이지씩 넘기기


**리눅스 명령어 기초**
sudo (superuser do)
-> 현재 계정에서 root 권한을 이용하여 명령어를 실행할 때 사용

sudo -i/sudo -s - root 계정으로 전환가능


** Command Line Interface **
GUI vs CLI
GUI 윈도우 시스템, 아이콘, 메뉴, 포인팅 디바이스 등의 요소에 의해 구성되는 컴퓨터 조직 환경
CLI 가상 터미널 또는 터미널을 통해 사용자와 컴퓨터가 상호 작용하는 방식 [GUI가 할 수 있는 모든 작업은 CLI로 할 수 있다]

**IO Redirection**
UNIX programs
input -
program arguments(프로그램 인수)
[제어 정보 control information]
environment variables(환경 변수)
[상태 정보 state information]
standard input(표준 입력)
[데이터 data]
output -
return status code(반환 상태 코드)
[제어 정보 control information]
standard out(표준 출력)
[데이터 data]
standard error(표준 에러)
[에러 메세지 error messages]
활용 -
ls -la > result.txt
['>' 를 이용하면 모니터에 출력될 파일리스트를 result.txt라는 파일에 입력으로 넣을 수 있다]
rm result.txt 2> result2.txt
[rm result.txt 에 대한 오류메세지가 result2.txt에 담긴다]
Append
활용 -
ls -al >> result.txt
(ls -al 실행결과가 result.txt에 담긴다)
mail ((이메일주소)) << eot
> i
> want to go home...
[이메일에 다음 내용이 전송됨]
ls -al > /dev/null
[실행결과가 /dev/null로 리다이렉션된다,즉 실행결과 삭제된다]

**쉘과 커널**
bash vs zsh
bash(Bourne-Again Shell):
GNU 프로젝트의 일환으로 개발됨 리눅스의 기본 쉘
zsh
bash와 마찬가지로 sh의 확장된 버전이다
장점 -
자동CD
재귀 경로 확장
철자 교정 및 대략적인 완성
플러그인 및 테마지원
