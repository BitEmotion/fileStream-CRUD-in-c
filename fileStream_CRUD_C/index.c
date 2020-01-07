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
		perror("���� �б� ��Ʈ���� ���� ���߽��ϴ�.");
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
				case 0: // ������ �ε���
					break;
				case 1: // ȸ�� �̸� �ҷ�����
					strcpy(memberArray[memberArrayCount].name, readStreamData);
					break;
				case 2: // ����ó �ҷ�����
					strcpy(memberArray[memberArrayCount].phoneNumber, readStreamData);
					break;
				case 3: // �ּ� �ҷ�����
					strcpy(memberArray[memberArrayCount].address, readStreamData);
					break;
				case 4: // �̸��� �ҷ�����
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
		printf("===== M E N U ���� ===== \n");
		printf("1. ȸ������ �߰� \n");
		printf("2. ȸ������ ���� \n");
		printf("3. ȸ������ ��ȸ \n");
		printf("4. ȸ������ ���� \n");
		printf("5. ����(������) \n");
		printf("======================== \n");
		printf("�����ϼ��� : ");

		scanf_s("%d", &selectedMenuNumber);
		// scanf���� ������ �ް� ���͸� ������ �Է¹���(stdin)�� \n(�� �ٲ޹��� == ����)�� ���� �Է°��� �����ְ� �ȴ�
		// �׷��� �Է¹���(stdin)�� �ִ� \n�� �����ؾ� ������ �Է¹޴� �����Ϳ� ������ ���� �ʴ´�.
		while (getchar() != '\n');

		if (selectedMenuNumber == 1) { //�߰�
			printf("�޴� ���� ��ȣ : 1 \n");
			printf("ȸ�� �̸��� �����ּ��� : ");
			fgets(memberArray[memberArrayCount].name, sizeof(memberArray[memberArrayCount].name), stdin);

			printf("����ó�� �����ּ��� : ");
			fgets(memberArray[memberArrayCount].phoneNumber, sizeof(memberArray[memberArrayCount].phoneNumber), stdin);

			printf("�ּҸ� �����ּ��� : ");
			fgets(memberArray[memberArrayCount].address, sizeof(memberArray[memberArrayCount].address), stdin);

			printf("�̸����� �����ּ��� : ");
			fgets(memberArray[memberArrayCount].email, sizeof(memberArray[memberArrayCount].email), stdin);

			printf("\n");
			printf("ȸ�������� �߰��Ǿ����ϴ�.\n");
			printf("\n");

			printf("ȸ�� �̸� : %s", memberArray[memberArrayCount].name);
			printf("����ó : %s", memberArray[memberArrayCount].phoneNumber);
			printf("�ּ� : %s", memberArray[memberArrayCount].address);
			printf("eMail : %s", memberArray[memberArrayCount].email);

			printf("\n");
			memberArrayCount++;
		}
		else if (selectedMenuNumber == 2) { // ����
			printf("�޴� ���� ��ȣ : 2 \n");
			printf("\n");
			printf("�����ϰ� ���� ��� �̸�:");

			char searchedName[ARRAY_LENGTH];
			fgets(searchedName, sizeof(searchedName), stdin);

			int isFounded;
			for (int i = 0; i < memberArrayCount; i++) {
				//strcmp�Լ��� �� ���ڿ��� ������ �� -> ������ 0, �ٸ��� 0�� �ƴ� �������� �����Ѵ�
				isFounded = strcmp(memberArray[i].name, searchedName);
				if (isFounded == 0) {

					printf("\n");
					printf("�����ϰ� ���� ������\n");
					printf("\n");

					printf("ȸ�� �̸� : %s", memberArray[i].name);
					printf("����ó : %s", memberArray[i].phoneNumber);
					printf("�ּ� : %s", memberArray[i].address);
					printf("eMail : %s", memberArray[i].email);

					printf("���ο� ȸ�� �̸��� �����ּ��� : ");
					fgets(memberArray[i].name, sizeof(memberArray[i].name), stdin);

					printf("���ο� ����ó�� �����ּ��� : ");
					fgets(memberArray[i].phoneNumber, sizeof(memberArray[i].phoneNumber), stdin);

					printf("���ο� �ּҸ� �����ּ��� : ");
					fgets(memberArray[i].address, sizeof(memberArray[i].address), stdin);

					printf("���ο� �̸����� �����ּ��� :  ");
					fgets(memberArray[i].email, sizeof(memberArray[i].email), stdin);
					break;
				}
			}
			if (isFounded != 0) {
				printf("ã�� ���߽��ϴ�.\n");
				printf("\n");
			}
		}
		else if (selectedMenuNumber == 3) {  // ��ȸ
			printf("�޴� ���� ��ȣ : 3 \n");
			printf("\n");
			printf("��ȸ�ϰ� ���� ��� �̸�:");

			char searchedName[ARRAY_LENGTH];
			fgets(searchedName, sizeof(searchedName), stdin);

			int isFounded;
			for (int i = 0; i < memberArrayCount; i++) {
				//strcmp�Լ��� �� ���ڿ��� ������ �� -> ������ 0, �ٸ��� 0�� �ƴ� �������� �����Ѵ�
				isFounded = strcmp(memberArray[i].name, searchedName);
				if (isFounded == 0) {
					printf("\n");
					printf("ȸ�� �̸� : %s", memberArray[i].name);
					printf("����ó : %s", memberArray[i].phoneNumber);
					printf("�ּ� : %s", memberArray[i].address);
					printf("eMail : %s", memberArray[i].email);
					printf("\n");
					break;
				}
			}
			if (isFounded != 0) {
				printf("ã�� ���߽��ϴ�.\n");
				printf("\n");
			}
		}
		else if (selectedMenuNumber == 4) { // ����
			printf("�޴� ���� ��ȣ : 4 \n");
			printf("\n");
			printf("�����ϰ� ���� ��� �̸�:");
			char searchedName[ARRAY_LENGTH];
			fgets(searchedName, sizeof(searchedName), stdin);

			int isFounded;
			for (int i = 0; i < memberArrayCount; i++) {
				isFounded = strcmp(memberArray[i].name, searchedName);
				if (isFounded == 0) {
					printf("\n");
					printf("�����ϰ� ���� �����͸� �����߽��ϴ�.\n");
					printf("\n");

					printf("ȸ�� �̸� : %s", memberArray[i].name);
					printf("����ó : %s", memberArray[i].phoneNumber);
					printf("�ּ� : %s", memberArray[i].address);
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
				printf("������ ȸ�� �̸��� ã�� ���߽��ϴ�.\n");
				printf("\n");
			}
		}
		else if (selectedMenuNumber == 5) { // ����
			printf("�޴� ���� ��ȣ : 4 \n");
			break;
			printf("\n");
		}
		else { // 1, 2, 3, 4 �� �ƴ� �ٸ���ȣ�� �Է����� �� �޴� ����â���� ���ư���.
			printf("\n");
			continue;
		}
	}

	FILE* fileWriteStream = fopen("memberData.txt", "w");
	if (fileWriteStream == NULL) {
		perror("���� ���� ��Ʈ���� ���� ���߽��ϴ�.");
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
		perror("���� ���� ��Ʈ���� ���� ���߽��ϴ�.");
		return;
	};

	if (fclose(fileReadStream) != 0) {
		perror("���� �б� ��Ʈ���� ���� ���߽��ϴ�.");
		return;
	};
	return 0;
}