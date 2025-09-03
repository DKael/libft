# Libft

## 1. 프로젝트 소개

Libft는 C 표준 라이브러리(libc)의 핵심 함수들을 직접 구현하여, 이후 모든 C 언어 기반 42서울 프로젝트에서 사용할 수 있는 나만의 라이브러리를 만드는 과제입니다. 문자열 처리, 메모리 조작, 입출력 함수뿐만 아니라 연결 리스트와 같은 자료구조 유틸리티도 포함됩니다.


## 2. 과제 목표
	•	C 언어 기본기를 단단히 다지고, 표준 함수의 동작 원리를 깊이 이해하기 위함
	•	포인터와 메모리 관리 능력 강화 (동적 할당, 메모리 누수 방지 습관)
	•	함수 단위로 모듈화하여 재사용 가능한 라이브러리를 작성하는 경험
	•	이후 과제에서 신뢰성 있게 활용할 수 있도록 견고하고 버그 없는 코드 작성 습관 확립


## 3. 구현 사항
	•	문자열 함수: ft_strlen, ft_strlcpy, ft_strlcat, ft_toupper, ft_tolower, ft_strchr, ft_strrchr, ft_strncmp, ft_strnstr, ft_strdup, ft_substr, ft_strjoin, ft_strtrim, ft_split, ft_strmapi, ft_striteri
	•	메모리 함수: ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp, ft_calloc
	•	문자/숫자 처리 함수: ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint, ft_atoi, ft_itoa
	•	입출력 함수: ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd
	•	연결 리스트 유틸리티: ft_lstnew, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back, ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap


## 4. 배운 점
	•	포인터 연산과 메모리 주소에 대한 깊은 이해
	•	NULL 처리, 예외 상황 방어 코드 작성 습관
	•	코드 재사용성을 높이는 함수 설계 방법
	•	성능을 고려한 구현 방식 (불필요한 복사 줄이기, 효율적인 메모리 사용)
	•	철저한 테스트를 통해 버그 없는 라이브러리의 중요성을 학습


## 5. 사용 방법
#### 라이브러리 빌드 방법

기본 사항만 빌드할 때: make

연결 리스트 유틸리티 포함 빌드할 때: make bonus

-> 결과물: libft.a 정적 라이브러리 생성

---

#### 다른 프로젝트에서 사용 예시 (main.c와 함께 링크)

gcc main.c -L. -lft -o main

./main


## 6. 기술 스택
	•	언어: C
	•	빌드 도구: GNU Make
	•	개발 환경: Unix/Linux (터미널 기반)
