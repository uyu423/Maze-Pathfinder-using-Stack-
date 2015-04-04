# Maze-Pathfinder-using-Stack-
2015 Catholic University of Korea. 'Fundamentals of Data Structures in C' Project 01

과제로 만든 __Maze Pathfinder__ 입니다. 네. 그냥 미로 길찾기에요. 개인적으로 이것저것 많은 요소가 들어간 프로그램이고, C에서 나름 __모듈화__ 하려고 발광했던 프로젝트라 github에 등록. Makefile 처음 만들어 봤는데 이게 제일 어려웠어요.

### 문제
* miro.txt 파일을 입력으로 받아 미로 출구 찾기 프로그래밍을 수행
* 미로의 크기는 최대 50 * 50 을 넘어서지 않는다
* miro.txt 의 내용

        4 5 // 행과 열을 스페이스로 구분
        01000 // 1은 벽을 의미 , (0,0)에서 출발 (3,4)가 종료
        00110
        10111
        00000

* 출력 (3,4) <- (3,3)<-(3,2)<- (2,1)<-(1,1)<-(0,0) 으로 path 출력
* 존재하지 않는 경우 "존재하지 않습니다." 출력

### 코딩 Overview
1. miro.txt 를 {1, 1} 인덱스 부터 받은 후 위, 아래, 좌, 우를 모두 '1'로 박아 __배열 밖으로 탈출하는 것을 방지__한다.
2. __offset 이라는 구조체를 사용해 상, 하, 좌, 우, 좌상, 우상, 좌하, 우하. __8방향의 인덱스 변화를 모두 배열로__ 박아놓는다.
3. Stack은 처음에 2개만 malloc으로 만들어 놓고 __Stack Full시 realloc__을 통해 (현재 stack크기 * 2) 만큼 늘린다. 
4. 경로를 탐색하는 PathFinder() 친구는 시작 지점 {1, 1}을 Stack에 박고 Top을 1증가 시킨 후 시작한다.
5. Miro.txt가 저장되는 maze 배열 외에 __mark 배열을 사용해 지나간 경로를 체크__한다.
6. 탐색 시 __다음 경로(nextRow, nextCol)을 체크__하여 Goal 인지 아니지, 진행 가능한 경로인지 아닌지 체크한다.
7. Stack을 사용한 탐색은 __Recursion이 아닌 While 반복문으로 작성__되었다.

### 문제'점'
* 처음에 파일입출력 코딩할 때 문제를 제대로 안 읽어서 첫 행의 행, 열 값 주는 것을 고려하지 않고 코딩함. (소스상에서 Maze 크기를 직접 계산) -> src/func.c 의 77~80 Line을 추가함으로써 해결. __문제를 잘 읽읍시다.__ 이 4줄을 삭제하면 첫 행 없이도 실행 가능.
* 마찬가지로 문제를 똑바로 안읽어서 미로 칸 사이에 ' '(스페이스)가 있어도 제대로 읽어들여옴. 이건 문제점 보다는 부가기능..
* StackPop() 함수에서 스택이 비었을때 뭔가 처리 하는 부분이 있기는 하지만 PathFinder() 함수가 굴러가면서 Empty Stack이 발생하는 경우가 없다.
* 지금 보니 __offset 구조체와 __mazeSize 구조체의 멤버 변수가 똑같다;;;;

### Properties Overview
*	ProjectName	: DSB Proj.1 Maze Finder (Stack)
*	Corder 		: Yu Yongwoo (YoWu)
*	Organiz.	: Catholic Univ. of Korea
*	Major		: Computer Science (Minor : Infomation System Eng)
*	StudentNum	: 201021395
*	DateTime	: 2015.4.1(Mon) 13:34
*	Contact		: uyu423@gmail.com (http://luckyyowu.tistory.com)
*	Develop OS	: CentOS Linux 6.6 x86 (kernel 2.6.32-504)
*	PorgramLang	: C (Library Model : POSIX)
*	TextEditor	: VIM - Vi IMproved 7.2
*	Encording	: UTF-8 (Linux Basic)
*	Compiler	: GCC 4.4.7

### 컴파일
* __Make__ : ...그냥 컴파일
* __Make clean__ : 재컴파일을 위한 오브젝트 파일, 실행 파일 삭제

### 그냥 설명
* __src/__ : *.c, *.h 파일 디렉토리
* __src/main.c__ : 메인 함수 부분
* __src/func.c__ : Maze 생성 및 관련 함수 정의 부분
* __src/stack.c__ : Stack 알고리즘 관련 함수 정의 부분
* __src/debug.c__ : Debugging 함수 정의 부분
* __src/head.h__ : 각종 함수들 전방 선언, struct, enum 선언 헤더
* __Makefile__ : 컴파일 규칙 명명
* __maze.txt__ : 실행 파일 예제
