#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <string.h>

#define ARRAY_LENGTH (50)

typedef struct Member_t {
	char name[ARRAY_LENGTH];
	char phoneNumber[ARRAY_LENGTH];
	char address[ARRAY_LENGTH];
	char email[ARRAY_LENGTH];
} Member_t;

int main(void) {
	Member_t memberArray[ARRAY_LENGTH] = { 0 };

	FILE* fileReadStream = fopen("memberData.txt", "r");

	if (fileReadStream == NULL) {
		perror("파일 읽기 스트림을 열지 못했습니다.");
		return;
	}

	int memberArrayCount = 0;
	char readStreamData[ARRAY_LENGTH];
	while (1) {
		for (int i = 0; i < 5; i++) {
			if (fgets(readStreamData, ARRAY_LENGTH, fileReadStream) == NULL) {
				goto NEXT_CODE;
			}
			else {
				switch (i) {
				case 0: // 데이터 인덱스
					break;
				case 1: // 회원 이름 불러오기
					strcpy(memberArray[memberArrayCount].name, readStreamData);
					break;
				case 2: // 연락처 불러오기
					strcpy(memberArray[memberArrayCount].phoneNumber, readStreamData);
					break;
				case 3: // 주소 불러오기
					strcpy(memberArray[memberArrayCount].address, readStreamData);
					break;
				case 4: // 이메일 불러오기
					strcpy(memberArray[memberArrayCount].email, readStreamData);
					break;
				default:
					break;
				}
			}
		}
		memberArrayCount++;
	}
NEXT_CODE:;

	int selectedMenuNumber = 0;
	while (1) {
		printf("===== M E N U 선택 ===== \n");
		printf("1. 회원정보 추가 \n");
		printf("2. 회원정보 수정 \n");
		printf("3. 회원정보 조회 \n");
		printf("4. 회원정보 삭제 \n");
		printf("5. 종료(끝내기) \n");
		printf("======================== \n");
		printf("선택하세요 : ");

		scanf_s("%d", &selectedMenuNumber);
		// scanf에서 정수를 받고 엔터를 누르면 입력버퍼(stdin)에 \n(줄 바꿈문자 == 엔터)에 대한 입력값은 남아있게 된다
		// 그래서 입력버퍼(stdin)에 있는 \n를 제거해야 다음에 입력받는 데이터에 영향을 주지 않는다.
		while (getchar() != '\n');

		if (selectedMenuNumber == 1) { //추가
			printf("메뉴 선택 번호 : 1 \n");
			printf("회원 이름을 적어주세요 : ");
			fgets(memberArray[memberArrayCount].name, sizeof(memberArray[memberArrayCount].name), stdin);

			printf("연락처를 적어주세요 : ");
			fgets(memberArray[memberArrayCount].phoneNumber, sizeof(memberArray[memberArrayCount].phoneNumber), stdin);

			printf("주소를 적어주세요 : ");
			fgets(memberArray[memberArrayCount].address, sizeof(memberArray[memberArrayCount].address), stdin);

			printf("이메일을 적어주세요 : ");
			fgets(memberArray[memberArrayCount].email, sizeof(memberArray[memberArrayCount].email), stdin);

			printf("\n");
			printf("회원정보가 추가되었습니다.\n");
			printf("\n");

			printf("회원 이름 : %s", memberArray[memberArrayCount].name);
			printf("연락처 : %s", memberArray[memberArrayCount].phoneNumber);
			printf("주소 : %s", memberArray[memberArrayCount].address);
			printf("eMail : %s", memberArray[memberArrayCount].email);

			printf("\n");
			memberArrayCount++;
		}
		else if (selectedMenuNumber == 2) { // 수정
			printf("메뉴 선택 번호 : 2 \n");
			printf("\n");
			printf("수정하고 싶은 사람 이름:");

			char searchedName[ARRAY_LENGTH];
			fgets(searchedName, sizeof(searchedName), stdin);

			int isFounded;
			for (int i = 0; i < memberArrayCount; i++) {
				//strcmp함수는 두 문자열이 같은지 비교 -> 같으면 0, 다르면 0이 아닌 정수값을 리턴한다
				isFounded = strcmp(memberArray[i].name, searchedName);
				if (isFounded == 0) {

					printf("\n");
					printf("수정하고 싶은 데이터\n");
					printf("\n");

					printf("회원 이름 : %s", memberArray[i].name);
					printf("연락처 : %s", memberArray[i].phoneNumber);
					printf("주소 : %s", memberArray[i].address);
					printf("eMail : %s", memberArray[i].email);

					printf("새로운 회원 이름을 적어주세요 : ");
					fgets(memberArray[i].name, sizeof(memberArray[i].name), stdin);

					printf("새로운 연락처를 적어주세요 : ");
					fgets(memberArray[i].phoneNumber, sizeof(memberArray[i].phoneNumber), stdin);

					printf("새로운 주소를 적어주세요 : ");
					fgets(memberArray[i].address, sizeof(memberArray[i].address), stdin);

					printf("새로운 이메일을 적어주세요 :  ");
					fgets(memberArray[i].email, sizeof(memberArray[i].email), stdin);
					break;
				}
			}
			if (isFounded != 0) {
				printf("찾지 못했습니다.\n");
				printf("\n");
			}
		}
		else if (selectedMenuNumber == 3) {  // 조회
			printf("메뉴 선택 번호 : 3 \n");
			printf("\n");
			printf("조회하고 싶은 사람 이름:");

			char searchedName[ARRAY_LENGTH];
			fgets(searchedName, sizeof(searchedName), stdin);

			int isFounded;
			for (int i = 0; i < memberArrayCount; i++) {
				//strcmp함수는 두 문자열이 같는지 비교 -> 같으면 0, 다르면 0이 아닌 정수값을 리턴한다
				isFounded = strcmp(memberArray[i].name, searchedName);
				if (isFounded == 0) {
					printf("\n");
					printf("회원 이름 : %s", memberArray[i].name);
					printf("연락처 : %s", memberArray[i].phoneNumber);
					printf("주소 : %s", memberArray[i].address);
					printf("eMail : %s", memberArray[i].email);
					printf("\n");
					break;
				}
			}
			if (isFounded != 0) {
				printf("찾지 못했습니다.\n");
				printf("\n");
			}
		}
		else if (selectedMenuNumber == 4) { // 삭제
			printf("메뉴 선택 번호 : 4 \n");
			printf("\n");
			printf("삭제하고 싶은 사람 이름:");
			char searchedName[ARRAY_LENGTH];
			fgets(searchedName, sizeof(searchedName), stdin);

			int isFounded;
			for (int i = 0; i < memberArrayCount; i++) {
				isFounded = strcmp(memberArray[i].name, searchedName);
				if (isFounded == 0) {
					printf("\n");
					printf("삭제하고 싶은 데이터를 삭제했습니다.\n");
					printf("\n");

					printf("회원 이름 : %s", memberArray[i].name);
					printf("연락처 : %s", memberArray[i].phoneNumber);
					printf("주소 : %s", memberArray[i].address);
					printf("eMail : %s", memberArray[i].email);
					printf("\n");

					for (int j = 0; j < memberArrayCount; j++) {
						Member_t* p_tempMember = &memberArray[i + j];
						Member_t* p_member_next = &memberArray[i + j + 1];
						*p_tempMember = *p_member_next;
					}
					memberArrayCount--;

					break;
				}
			}
			if (isFounded != 0) {
				printf("삭제할 회원 이름을 찾지 못했습니다.\n");
				printf("\n");
			}
		}
		else if (selectedMenuNumber == 5) { // 종료
			printf("메뉴 선택 번호 : 4 \n");
			break;
			printf("\n");
		}
		else { // 1, 2, 3, 4 가 아닌 다른번호을 입력했을 때 메뉴 선택창으로 돌아간다.
			printf("\n");
			continue;
		}
	}

	FILE* fileWriteStream = fopen("memberData.txt", "w");
	if (fileWriteStream == NULL) {
		perror("파일 쓰기 스트림을 열지 못했습니다.");
		return;
	}

	for (int j = 0; j < memberArrayCount; j++) {
		fprintf(fileWriteStream, "%d \n", j);
		fprintf(fileWriteStream, "%s", memberArray[j].name);
		fprintf(fileWriteStream, "%s", memberArray[j].phoneNumber);
		fprintf(fileWriteStream, "%s", memberArray[j].address);
		fprintf(fileWriteStream, "%s", memberArray[j].email);
	}

	if (fclose(fileWriteStream) != 0) {
		perror("파일 쓰기 스트림을 닫지 못했습니다.");
		return;
	};

	if (fclose(fileReadStream) != 0) {
		perror("파일 읽기 스트림을 닫지 못했습니다.");
		return;
	};
	return 0;
}