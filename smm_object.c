//
//  smm_node.c
//  SMMarble
//
//  Created by Juyeop Kim on 2023/11/05.
//

#include "smm_common.h"
#include "smm_object.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODETYPE    7
#define MAX_GRADE       9
#define MAX_NODE        100
#define MAX_CHARNAME 	200
#define MAX_LINELENGTH	4
#define SMMNODE_TYPE_MAX	7


static char smmNodeName[SMMNODE_TYPE_MAX][MAX_CHARNAME] = {
       "����",
       "�Ĵ�",
       "�����",
       "��",
       "����Ƿ��̵�",
       "��������",
       "�����ð�"
};

char* smmObj_getTypeName(int type)
{
      return(char*)smmNodeName[type];
}


static smmObject_t smm_node[MAX_NODE];

//3. ���� �Լ� ����
//object generation
void smmObj_genObject(char* name, smmObjType_e objType, int type, int credit, int energy, smmObjGrade_e grade){
	smmObject_t* ptr;
    
    ptr = (smmObject_t*)malloc(sizeof(smmObject_t));
    
    strcpy(ptr->name, name);
    ptr->objType = smmObjType_board;
    ptr->type = type;
    ptr->credit = credit;
    ptr->energy = energy;
    ptr->grade = grade;
    
    return ptr;
}

//member retrieving
char* smmObj_getNodeName(void* obj)
{
    smmObject_t* ptr = (smmObject_t*)obj;
    
    return ptr->name;
}

int smmObj_getNodeType(int node_nr)
{
    return smm_node[node_nr].type;
}


int smmObj_getNodeCredit(int node_nr)
{
    return smm_node[node_nr].credit;
}

int smmObj_getGradeEnergy(int node_nr)
{
    return smm_node[node_nr].energy;
}

// ����ü ����: foodcard
	typedef struct FoodCard {
    	char name[MAX_CHARNAME];
    	int energyBoost;
    	int energyBonus;
    	// �ٸ� �ʿ��� �������� �߰��� �� ����
	} FoodCard;

//����ü ����: festivalcard

	// ����ü ����
	typedef struct FestivalCard {
    	char name[MAX_CHARNAME];
    	char mission[MAX_CHARNAME];
    	// �ٸ� �ʿ��� �������� �߰��� �� ����
	} FestivalCard; 
