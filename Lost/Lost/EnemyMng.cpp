#include"EnemyMng.h"
#include"Value.h"
#include"Chore.h"
#include"Obj.h"

Dot decoi_e[4];
Dot DEST1[27];
Dot DEST2[20];
int SonWalk[4];
int DaughterWalk[4];
int HusbandWalk[4];
int MadamWalk[4];

int kakashi_e;

int Enemy::Set(int speed, int floor) {
	if (floor == 1) {
		kakashi_e = GetRand() % 27;//0~19
		enemy.Set(DEST1[kakashi_e], enemy.GetRadius(), 0);
		nextNum = kakashi_e;
	}
	if (floor == 2) {
		kakashi_e = GetRand() % 20;//0~19
		enemy.Set(DEST2[kakashi_e], enemy.GetRadius(), 0);
		nextNum = kakashi_e;
	}
	//printfDx("%d", nextNum);
	move.Set(0, 0);
	stateflag = 0;
	Speed = speed;
	esound.Initialzie();
	return 0;
}

//Dot dest_ene;
int Enemy::Updata(Circle player,int floor,int half,int full,int flag,int count,SoundMng psound) {
	if (psound.isHitDot(enemy.GetDot(), count)) {
		if (stateflag != 2) {
			stateflag = 2;
			PlayChaseBGM();
		}
	}
	if (floor == 2) {
		if (stateflag == 0) {	//�ۏ�,nextNum�̏�Ƃ����O��
			//StopChaseBGM();
			kakashi_e = GetRand() % 100;
			switch (nextNum + 1)	//��������1base
			{
			case 1:
				if (kakashi_e < 20) {
					nextNum = 6 - 1;
				}
				else if (kakashi_e < 20 + 60) {
					nextNum = 3 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 2 - 1;
				}
				break;
			case 2:
				if (kakashi_e < 80) {
					nextNum = 1 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 19 - 1;
				}
				break;
			case 3:
				if (kakashi_e < 20) {
					nextNum = 1 - 1;
				}
				else if (kakashi_e < 20 + 20) {
					nextNum = 4 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 5 - 1;
				}
				break;
			case 4:
				if (kakashi_e < 20) {
					nextNum = 20 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 3 - 1;
				}
				break;
			case 5:
				if (kakashi_e < 20) {
					nextNum = 3 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 8 - 1;
				}
				break;
			case 6:
				if (kakashi_e < 20) {
					nextNum = 7 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 1 - 1;
				}
				break;
			case 7:
				if (kakashi_e < 100) {
					nextNum = 6 - 1;
				}
				break;
			case 8:
				if (kakashi_e < 20) {
					nextNum = 9 - 1;
				}
				else if (kakashi_e < 20 + 20) {
					nextNum = 5 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 12 - 1;
				}
				break;
			case 9:
				if (kakashi_e < 20) {
					nextNum = 10 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 8 - 1;
				}
				break;
			case 10:
				if (kakashi_e < 20) {
					nextNum = 11 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 9 - 1;
				}
				break;
			case 11:
				if (kakashi_e < 100) {
					nextNum = 10 - 1;
				}
				break;
			case 12:
				if (kakashi_e < 20) {
					nextNum = 8 - 1;
				}
				else if (kakashi_e < 20 + 60) {
					nextNum = 16 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 13 - 1;
				}
				break;
			case 13:
				if (kakashi_e < 20) {
					nextNum = 14 - 1;
				}
				else if (kakashi_e < 20 + 20) {
					nextNum = 15 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 12 - 1;
				}
				break;
			case 14:
				if (kakashi_e < 100) {
					nextNum = 13 - 1;
				}
				break;
			case 15:
				if (kakashi_e < 100) {
					nextNum = 13 - 1;
				}
				break;
			case 16:
				if (kakashi_e < 20) {
					nextNum = 12 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 17 - 1;
				}
				break;
			case 17:
				if (kakashi_e < 20) {
					nextNum = 18 - 1;
				}
				else if (kakashi_e < 20 + 20) {
					nextNum = 16 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 19 - 1;
				}
				break;
			case 18:
				if (kakashi_e < 100) {
					nextNum = 17 - 1;
				}
				break;
			case 19:
				if (kakashi_e < 20) {
					nextNum = 17 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 2 - 1;
				}
				break;
			case 20:
				if (kakashi_e < 100) {
					nextNum = 4 - 1;
				}
				break;
			default:
				break;
			}
			UpdataMove(DEST2[nextNum]);
			//dest = dest_ene;
			stateflag = 1;
		}
		else if (stateflag == 1) {//����,��
			//StopChaseBGM();
			Speed = half;
			/*if (!flag)
				printfDx("�����H�H�H�H�H�H\n");*/
			//enemy.MoveandTurn(dest);
			if (CalcDistance(enemy.GetDot(), DEST2[nextNum]) < ONPOINT) {	//�ۏ�ɂ����
				/*if(!flag)
					printfDx("�����I�I�I�I�I�I�I�I�I�I�I�I�I\n");*/
				stateflag = 0;
			}
			UpdataMove(DEST2[nextNum]);
		}
		else if (stateflag == 2) {//�v���C���[��ڎ�
			//PlayChaseBGM();
			//printfDx("�ڎ��I�I\n");
			Speed = full;
			if (GetWall().IsHitDottoDot(enemy.GetDot(), player.GetDot(), GetFloor2SoftHandle())) {//�ǉz����������
				//DrawFormatString(0,40,GREEN,"�ǉz���I�I\n");
				stateflag = 3;
			}
			UpdataMove(player.GetDot());
		}
		else if (stateflag == 3) {//�v���C���[�T��
			//PlayChaseBGM();
			Speed = full;
			//������ρC�s����_��T���čs��
			double minDistance = 10000.0;
			int ableNum[20];
			int ablenum = 0;
			for (int i = 0; i < 20; i++) {
				if (!GetWall().IsHitDottoDot(enemy.GetDot(), DEST2[i], GetFloor2SoftHandle()) &&	//�ǂ��h�A�����������Ȃ����
					!GetDoor().IsHitDottoDot(enemy.GetDot(), DEST2[i], GetFloor2SoftHandle()) &&
					!GetRock().IsHitDottoDot(enemy.GetDot(), DEST2[i], GetFloor2SoftHandle())
					) {
					ableNum[ablenum++] = i;	//�s����_��20�܂�keep
					if (ablenum >= 20) break;
				}
			}
			double minDir = 2.0 * PI;
			int minDirNum;
			for (int i = 0; i < ablenum; i++) {
				if (CalcDirDiff(enemy.GetDir(), CalcDir(enemy.GetDot(), DEST2[ableNum[i]])) < minDir) {	//�g����_�̂����C��Ԍ������Ă�����Ɩ������Ȃ����
					minDir = CalcDirDiff(enemy.GetDir(), CalcDir(enemy.GetDot(), DEST2[ableNum[i]]));
					minDirNum = ableNum[i];
				}
			}
			UpdataMove(DEST2[minDirNum]);
			stateflag = 1;
			StopChaseBGM();
			nextNum = minDirNum;
		}

		if (player&enemy) {
			return 1;
		}

		/*------���G�X�V-------*/
		decoi_e[0].Set(
			enemy.Getx() + enemy.GetRadius() + DISP_WIDTH / 2.0 - player.Getx(),
			enemy.Gety() - SERCH_HEIGHT / 2.0 + DISP_HEIGHT / 2.0 - player.Gety());
		decoi_e[1].Set(
			enemy.Getx() + enemy.GetRadius() + DISP_WIDTH / 2.0 - player.Getx() + SERCH_WIDTH,
			enemy.Gety() + SERCH_HEIGHT / 2.0 + DISP_HEIGHT / 2.0 - player.Gety());
		serch.Set(decoi_e[0], decoi_e[1], enemy.GetDir());

		if (serch.isHitCenter(player.GetRadius(), enemy.GetRadius())) {//���G�͈͓��Ƀv���C���[������
			if (!GetWall().IsHitDottoDot(enemy.GetDot(), player.GetDot(), GetFloor2SoftHandle())) {//�ǉz���łȂ����
				//DrawFormatString(0,40,GREEN,"�ǉz���I�I\n");
				if (stateflag != 2) {
					PlaybeLooked();
					PlayChaseBGM();
					stateflag = 2;
				}
			}
			//stateflag = 2;
			//printfDx("�����I�I�I");
		}

		/*---------------�摜�X�V-----------------*/
		if (!(GetMove().Getx() == 0 && GetMove().Gety() == 0)) { //�ړ����Ă��
			enemy.SetDir(CalcDir(GetMove()));
			bodyClock++;
			if (bodyClock >= P_CLOCK) bodyClock = 0;
			if (stateflag == 2 || stateflag == 3) {//����
				if (bodyClock == 0 || bodyClock == P_CLOCK / 4 || bodyClock == P_CLOCK / 2 || bodyClock == P_CLOCK * 3 / 4) {
					if (CalcDistance(player.GetDot(), enemy.GetDot()) < 1500) {
						switch (flag) {
						case 0:
							PlaySonWalk();
							esound.Born(enemy.GetDot(), SOUND_SPEED, SON_SOUND_LIFESPAN, count);
							break;
						case 1:
							PlayDaughterWalk();
							esound.Born(enemy.GetDot(), SOUND_SPEED, DAUGHTER_SOUND_LIFESPAN, count);
							break;
						case 2:
							PlayHusbandWalk();
							esound.Born(enemy.GetDot(), SOUND_SPEED, HUSBAND_SOUND_LIFESPAN, count);
							break;
						case 3:
							PlayMadamWalk();
							esound.Born(enemy.GetDot(), SOUND_SPEED, MADAM_SOUND_LIFESPAN, count);
							break;
						default:
							break;
						}
					}
				}
			}
			else {//�x��
				if (bodyClock == 0 || bodyClock == P_CLOCK / 2) {
					if (CalcDistance(player.GetDot(), enemy.GetDot()) < 1500) {
						switch (flag) {
						case 0:
							PlaySonWalk();
							esound.Born(enemy.GetDot(), SOUND_SPEED, SON_SOUND_LIFESPAN, count);
							break;
						case 1:
							PlayDaughterWalk();
							esound.Born(enemy.GetDot(), SOUND_SPEED, DAUGHTER_SOUND_LIFESPAN, count);
							break;
						case 2:
							PlayHusbandWalk();
							esound.Born(enemy.GetDot(), SOUND_SPEED, HUSBAND_SOUND_LIFESPAN, count);
							break;
						case 3:
							PlayMadamWalk();
							esound.Born(enemy.GetDot(), SOUND_SPEED, MADAM_SOUND_LIFESPAN, count);
							break;
						default:
							break;
						}
					}
				}
			}
			//�A�j�����
			if (stateflag == 2 || stateflag == 3) {//����
				if (bodyClock == 0) {
					animeNum = 1;
				}
				else if (bodyClock == 5) {
					animeNum = 2;
				}
				else if (bodyClock == 10) {
					animeNum = 1;
				}
				else if (bodyClock == 15) {
					animeNum = 0;
				}
				else if (bodyClock == 20) {
					animeNum = 1;
				}
				else if (bodyClock == 25) {
					animeNum = 2;
				}
				else if (bodyClock == 30) {
					animeNum = 1;
				}
				else if (bodyClock == 35) {
					animeNum = 0;
				}
			}
			else {
				if (bodyClock == 0) {
					animeNum = 1;
				}
				else if (bodyClock == 10) {
					animeNum = 2;
				}
				else if (bodyClock == 20) {
					animeNum = 1;
				}
				else if (bodyClock == 30) {
					animeNum = 0;
				}
			}
		}
		if (enemy.GetDir() <= PI / 4.0 || enemy.GetDir() >= PI * 7.0 / 4.0) {
			Eimage = EWalkRight[animeNum];
		}
		else if (enemy.GetDir() >= PI / 4.0 && enemy.GetDir() <= PI * 3.0 / 4.0) {
			Eimage = EWalkUp[animeNum];
		}
		else if (enemy.GetDir() >= PI * 3.0 / 4.0 && enemy.GetDir() <= PI * 5.0 / 4.0) {
			Eimage = EWalkLeft[animeNum];
		}
		else if (enemy.GetDir() >= PI * 5.0 / 4.0 && enemy.GetDir() <= PI * 7.0 / 4.0) {
			Eimage = EWalkDown[animeNum];
		}

		/*------�ړ�---------*/
		/*-------�ǂ�-------*/
		if (GetDoor().IsHitMoving(enemy, GetFloor2SoftHandle())) {	//�h�A�ɂԂ����
			PlayerMoveInColor(&enemy, GetMove());
			return 0;
		}
		if (GetWall().IsHitMoving(enemy, GetFloor2SoftHandle())) {	//�ǂɂԂ����
			PlayerMoveInColor(&enemy, GetMove());
			return 0;
		}
		if (GetHighstep().IsHitCircle(enemy, GetFloor2SoftHandle())) {	//2�K�̊K�i�ɂ���Ƃ�
			PlayerMoveInColor(&enemy, GetMove());
			return 0;
		}
		enemy.MoveandTurn(GetMove());
	}
	else if (floor == 1) {
		if (stateflag == 0) {	//�ۏ�
			//StopChaseBGM();
			kakashi_e = GetRand() % 100;
			switch (nextNum + 1)	//��������1base
			{
			case 1:
				if (kakashi_e < 40) {
					nextNum = 2 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 6 - 1;
				}
				break;
			case 2:
				if (kakashi_e < 34) {
					nextNum = 1 - 1;
				}
				else if (kakashi_e < 34+33) {
					nextNum = 5 - 1;
				}
				else if (kakashi_e < 34 + 33 + 33) {
					nextNum = 3 - 1;
				}
				break;
			case 3:
				if (kakashi_e < 50) {
					nextNum = 2 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 4 - 1;
				}
				break;
			case 4:
				if (kakashi_e < 50) {
					nextNum = 3 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 5 - 1;
				}
				break;
			case 5:
				if (kakashi_e < 34) {
					nextNum = 6 - 1;
				}
				else if (kakashi_e < 34+33) {
					nextNum = 2 - 1;
				}
				else if (kakashi_e < 34 + 33 + 33) {
					nextNum = 4 - 1;
				}
				break;
			case 6:
				if (kakashi_e < 60) {
					nextNum = 11 - 1;
				}
				else if (kakashi_e < 60 + 20) {
					nextNum = 1 - 1;
				}
				else if (kakashi_e < 60 + 20 + 20) {
					nextNum = 5 - 1;
				}
				break;
			case 7:
				if (kakashi_e < 20) {
					nextNum = 8 - 1;
				}
				else if (kakashi_e < 100) {
					nextNum = 10 - 1;
				}
				break;
			case 8:
				if (kakashi_e < 100) {
					nextNum = 7 - 1;
				}
				break;
			case 9:
				if (kakashi_e < 100) {
					nextNum = 17 - 1;
				}
				break;
			case 10:
				if (kakashi_e < 20) {
					nextNum = 7 - 1;
				}
				else if (kakashi_e < 20+20) {
					nextNum = 11 - 1;
				}
				else if(kakashi_e < 20 + 20 + 80) {
					nextNum = 16 - 1;
				}
				break;
			case 11:
				if (kakashi_e < 20) {
					nextNum = 6 - 1;
				}
				else if (kakashi_e < 20 + 20) {
					nextNum = 12 - 1;
				}
				else if (kakashi_e < 20 + 20 + 60) {
					nextNum = 10 - 1;
				}
				break;
			case 12:
				if (kakashi_e < 70) {
					nextNum = 11 - 1;
				}
				else if (kakashi_e < 70 + 30) {
					nextNum = 13 - 1;
				}
				break;
			case 13:
				if (kakashi_e < 70) {
					nextNum = 12 - 1;
				}
				else if (kakashi_e < 70 + 30) {
					nextNum = 14 - 1;
				}
				break;
			case 14:
				if (kakashi_e < 20) {
					nextNum = 15 - 1;
				}
				else if (kakashi_e < 20 + 20) {
					nextNum = 21 - 1;
				}
				else if (kakashi_e < 20 + 20 + 60) {
					nextNum = 13 - 1;
				}
				break;
			case 15:
				if (kakashi_e < 10) {
					nextNum = 16 - 1;
				}
				else if (kakashi_e < 10+20) {
					nextNum = 18 - 1;
				}
				else if (kakashi_e < 10+20+20) {
					nextNum = 20 - 1;
				}
				else if (kakashi_e < 10 + 20 + 20+50) {
					nextNum = 14 - 1;
				}
				break;
			case 16:
				if (kakashi_e < 20) {
					nextNum = 17 - 1;
				}
				else if (kakashi_e < 20 + 20) {
					nextNum = 10 - 1;
				}
				else if (kakashi_e < 20 + 20 + 60) {
					nextNum = 15 - 1;
				}
				break;
			case 17:
				if (kakashi_e < 20) {
					nextNum = 9 - 1;
				}
				else if (kakashi_e < 20 + 80) {
					nextNum = 16 - 1;
				}
				break;
			case 18:
				if (kakashi_e < 100) {
					nextNum = 15 - 1;
				}
				break;
			case 19:
				if (kakashi_e < 100) {
					nextNum = 20 - 1;
				}
				break;
			case 20:
				if (kakashi_e < 20) {
					nextNum = 19 - 1;
				}
				else if (kakashi_e < 20+80) {
					nextNum = 15 - 1;
				}
				break;
			case 21:
				if (kakashi_e < 60) {
					nextNum = 14 - 1;
				}
				else if (kakashi_e < 60 + 20) {
					nextNum = 22 - 1;
				}
				else if (kakashi_e < 60 + 20 + 20) {
					nextNum = 25 - 1;
				}
				break;
			case 22:
				if (kakashi_e < 40) {
					nextNum = 23 - 1;
				}
				else if (kakashi_e < 40 + 60) {
					nextNum = 21 - 1;
				}
				break;
			case 23:
				if (kakashi_e < 60) {
					nextNum = 22 - 1;
				}
				else if (kakashi_e < 60 + 40) {
					nextNum = 24 - 1;
				}
				break;
			case 24:
				if (kakashi_e < 40) {
					nextNum = 23 - 1;
				}
				else if (kakashi_e < 40 + 40) {
					nextNum = 25 - 1;
				}
				else if (kakashi_e < 40 + 40 + 20) {
					nextNum = 26 - 1;
				}
				break;
			case 25:
				if (kakashi_e < 60) {
					nextNum = 22 - 1;
				}
				else if (kakashi_e < 60 + 40) {
					nextNum = 24 - 1;
				}
				break;
			case 26:
				if (kakashi_e < 20) {
					nextNum = 27 - 1;
				}
				else if (kakashi_e < 20 + 80) {
					nextNum = 24 - 1;
				}
				break;
			case 27:
				if (kakashi_e < 100) {
					nextNum = 26 - 1;
				}
				break;
			default:
				break;
			}
			UpdataMove(DEST1[nextNum]);
			//dest = dest_ene;
			stateflag = 1;
		}
		else if (stateflag == 1) {//����,��
			//StopChaseBGM();
			Speed = half;
			//enemy.MoveandTurn(dest);
			if (CalcDistance(enemy.GetDot(), DEST1[nextNum]) < ONPOINT) {	//�ۏ�ɂ����
				//printfDx("�����I�I�I�I�I�I�I�I�I�I�I�I�I\n");
				stateflag = 0;
			}
			UpdataMove(DEST1[nextNum]);
		}
		else if (stateflag == 2) {//�v���C���[��ڎ�
			//PlayChaseBGM();
			//printfDx("�ڎ��I�I\n");
			Speed = full;
			if (GetWall().IsHitDottoDot(enemy.GetDot(), player.GetDot(), GetFloor1SoftHandle())) {//�ǉz����������
				//DrawFormatString(0,40,GREEN,"�ǉz���I�I\n");
				stateflag = 3;
			}
			UpdataMove(player.GetDot());
		}
		else if (stateflag == 3) {//�v���C���[�T��
			//PlayChaseBGM();
			Speed = full;
			//������ρC�s����_��T���čs���āC��������p�x���݂ŋ߂��_��dest�ɂ���
			double minDistance = 10000.0;
			int ableNum[27];
			int ablenum = 0;
			for (int i = 0; i < 27; i++) {
				if (!GetWall().IsHitDottoDot(enemy.GetDot(), DEST1[i], GetFloor1SoftHandle()) &&	//�ǂ��h�A�����������Ȃ����
					!GetDoor().IsHitDottoDot(enemy.GetDot(), DEST1[i], GetFloor1SoftHandle()) &&
					!GetRock().IsHitDottoDot(enemy.GetDot(), DEST1[i], GetFloor1SoftHandle())
					) {
					ableNum[ablenum++] = i;	//�s����_��20�܂�keep
					if (ablenum >= 27) break;
				}
			}
			double minDir = 2.0 * PI;
			int minDirNum;
			for (int i = 0; i < ablenum; i++) {
				if (CalcDirDiff(enemy.GetDir(), CalcDir(enemy.GetDot(), DEST1[ableNum[i]])) < minDir) {	//�g����_�̂����C��Ԍ������Ă�����Ɩ������Ȃ����
					minDir = CalcDirDiff(enemy.GetDir(), CalcDir(enemy.GetDot(), DEST1[ableNum[i]]));
					minDirNum = ableNum[i];
				}
			}
			UpdataMove(DEST1[minDirNum]);
			stateflag = 1;
			nextNum = minDirNum;
		}
		
		if (player&enemy) {
			return 1;
		}

		/*------���G�X�V-------*/
		decoi_e[0].Set(
			enemy.Getx() + enemy.GetRadius() + DISP_WIDTH / 2.0 - player.Getx(),
			enemy.Gety() - SERCH_HEIGHT / 2.0 + DISP_HEIGHT / 2.0 - player.Gety());
		decoi_e[1].Set(
			enemy.Getx() + enemy.GetRadius() + DISP_WIDTH / 2.0 - player.Getx() + SERCH_WIDTH,
			enemy.Gety() + SERCH_HEIGHT / 2.0 + DISP_HEIGHT / 2.0 - player.Gety());
		serch.Set(decoi_e[0], decoi_e[1], enemy.GetDir());

		if (serch.isHitCenter(player.GetRadius(), enemy.GetRadius())) {//���G�͈͓��Ƀv���C���[������
			if (!GetWall().IsHitDottoDot(enemy.GetDot(), player.GetDot(), GetFloor1SoftHandle())) {//�ǉz���łȂ����
				 //DrawFormatString(0,40,GREEN,"�ǉz���I�I\n");
				if (stateflag != 2) {
					PlaybeLooked();
					PlayChaseBGM();
					stateflag = 2;
				}
			}
			//stateflag = 2;
			//printfDx("�����I�I�I");
		}

		/*---------------�摜�X�V-----------------*/
		if (!(GetMove().Getx() == 0 && GetMove().Gety() == 0)) { //�ړ����Ă��
			enemy.SetDir(CalcDir(GetMove()));
			bodyClock++;
			if (bodyClock >= P_CLOCK) bodyClock = 0;
			if (stateflag == 2 || stateflag == 3 ) {	//�����Ă���
				if (bodyClock == 0 || bodyClock == P_CLOCK / 2) {
					if (CalcDistance(player.GetDot(), enemy.GetDot()) < 1500) {
						switch (flag) {
						case 0:
							PlaySonWalk();
							esound.Born(enemy.GetDot(), SOUND_SPEED, SON_SOUND_LIFESPAN, count);
							break;
						case 1:
							PlayDaughterWalk();
							esound.Born(enemy.GetDot(), SOUND_SPEED, DAUGHTER_SOUND_LIFESPAN, count);
							break;
						case 2:
							PlayHusbandWalk();
							esound.Born(enemy.GetDot(), SOUND_SPEED, HUSBAND_SOUND_LIFESPAN, count);
							break;
						case 3:
							PlayMadamWalk();
							esound.Born(enemy.GetDot(), SOUND_SPEED, MADAM_SOUND_LIFESPAN, count);
							break;
						default:
							break;
						}
					}
					
				}
			}
			else {
				if (bodyClock == 0) {
					if (CalcDistance(player.GetDot(), enemy.GetDot()) < 1500) {
						switch (flag) {
						case 0:
							PlaySonWalk();
							esound.Born(enemy.GetDot(), SOUND_SPEED, SON_SOUND_LIFESPAN, count);
							break;
						case 1:
							PlayDaughterWalk();
							esound.Born(enemy.GetDot(), SOUND_SPEED, DAUGHTER_SOUND_LIFESPAN, count);
							break;
						case 2:
							PlayHusbandWalk();
							esound.Born(enemy.GetDot(), SOUND_SPEED, HUSBAND_SOUND_LIFESPAN, count);
							break;
						case 3:
							PlayMadamWalk();
							esound.Born(enemy.GetDot(), SOUND_SPEED, MADAM_SOUND_LIFESPAN, count);
							break;
						default:
							break;
						}
					}
				}
			}
			if (stateflag == 2 || stateflag == 3) {
				if (bodyClock == 0) {
					animeNum = 1;
				}
				else if (bodyClock == 4) {
					animeNum = 2;
				}
				else if (bodyClock == 7) {
					animeNum = 0;
				}
				else if (bodyClock == 10) {
					animeNum = 1;
				}
				else if (bodyClock == 14) {
					animeNum = 2;
				}
				else if (bodyClock == 17) {
					animeNum = 0;
				}
			}
			else {
				if (bodyClock == 0) {
					animeNum = 1;
				}
				else if (bodyClock == 8) {
					animeNum = 2;
				}
				else if (bodyClock == 14) {
					animeNum = 0;
				}
			}
		}
		if (enemy.GetDir() <= PI / 4.0 || enemy.GetDir() >= PI * 7.0 / 4.0) {
			Eimage = EWalkRight[animeNum];
		}
		else if (enemy.GetDir() >= PI / 4.0 && enemy.GetDir() <= PI * 3.0 / 4.0) {
			Eimage = EWalkUp[animeNum];
		}
		else if (enemy.GetDir() >= PI * 3.0 / 4.0 && enemy.GetDir() <= PI * 5.0 / 4.0) {
			Eimage = EWalkLeft[animeNum];
		}
		else if (enemy.GetDir() >= PI * 5.0 / 4.0 && enemy.GetDir() <= PI * 7.0 / 4.0) {
			Eimage = EWalkDown[animeNum];
		}

		/*------�ړ�---------*/
		/*-------�ǂ�-------*/
		if (GetDoor().IsHitMoving(enemy, GetFloor1SoftHandle())) {	//�h�A�ɂԂ����
			PlayerMoveInColor(&enemy, GetMove());
			return 0;
		}
		if (GetWall().IsHitMoving(enemy, GetFloor1SoftHandle())) {	//�ǂɂԂ����
			PlayerMoveInColor(&enemy, GetMove());
			return 0;
		}
		if (GetHighstep().IsHitCircle(enemy, GetFloor1SoftHandle())) {	//2�K�̊K�i�ɂ���Ƃ�
			PlayerMoveInColor(&enemy, GetMove());
			return 0;
		}
		enemy.MoveandTurn(GetMove());
	}
	return 0;
}

int Enemy::SoundDraw(Circle player, int count,int flag) {
	esound.Draw(player, count, RED, flag);
	return 0;
}
int Enemy::Draw(Dot player) {
	DrawModiGraph(
		enemy.Getx() + DISP_WIDTH / 2.0 - player.Getx() - enemy.GetRadius(), enemy.Gety() + DISP_HEIGHT / 2.0 - player.Gety() - enemy.GetRadius(),
		enemy.Getx() + DISP_WIDTH / 2.0 - player.Getx() + enemy.GetRadius(), enemy.Gety() + DISP_HEIGHT / 2.0 - player.Gety() - enemy.GetRadius(),
		enemy.Getx() + DISP_WIDTH / 2.0 - player.Getx() + enemy.GetRadius(), enemy.Gety() + DISP_HEIGHT / 2.0 - player.Gety() + enemy.GetRadius(),
		enemy.Getx() + DISP_WIDTH / 2.0 - player.Getx() - enemy.GetRadius(), enemy.Gety() + DISP_HEIGHT / 2.0 - player.Gety() + enemy.GetRadius(),
		Eimage, true);

	//serch.Draw(BLUE, enemy.GetRadius());
	return 0;
}

double dir_e;
int Enemy::UpdataMove(Dot a) {
	dir_e = CalcDir(enemy.GetDot(), a);
	//dir_e = CalcDir(enemy.GetDot().Getx() - a.Getx(), enemy.GetDot().Gety() - a.Gety());
	move.Set(Speed*cos(dir_e), -Speed*sin(dir_e));
	//printfDx("dir:%f,enedot(%f,%f),nextdot(%f,%f)\n", dir_e * 180.0 / PI ,enemy.GetDot().Getx(),enemy.GetDot().Gety(),a.Getx(),a.Gety());
	return 0;
}
Dot Enemy::GetMove() {
	return move;
}

int Husband::Initialize() {
	LoadDivGraph("images/enemies/husband/husband.png", 12, 3, 4, 32, 32, image);
	EWalkDown[0] = image[0];
	EWalkDown[1] = image[1];
	EWalkDown[2] = image[2];
	EWalkLeft[0] = image[3];
	EWalkLeft[1] = image[4];
	EWalkLeft[2] = image[5];
	EWalkRight[0] = image[6];
	EWalkRight[1] = image[7];
	EWalkRight[2] = image[8];
	EWalkUp[0] = image[9];
	EWalkUp[1] = image[10];
	EWalkUp[2] = image[11];
	animeNum = 1;

	HusbandWalk[0] = LoadSoundMem("sounds/husband/1.wav");
	HusbandWalk[1] = LoadSoundMem("sounds/husband/2.wav");
	HusbandWalk[2] = LoadSoundMem("sounds/husband/3.wav");
	HusbandWalk[3] = LoadSoundMem("sounds/husband/4.wav");

	Eimage = image[0];
	move.Set(0, 0);
	enemy.Set(0, 0, HUSBAND_RANGE, 0);
	return 0;
}
int Madam::Initialize() {
	LoadDivGraph("images/enemies/madam/madam.png", 12, 3, 4, 32, 32, image);
	EWalkDown[0] = image[0];
	EWalkDown[1] = image[1];
	EWalkDown[2] = image[2];
	EWalkLeft[0] = image[3];
	EWalkLeft[1] = image[4];
	EWalkLeft[2] = image[5];
	EWalkRight[0] = image[6];
	EWalkRight[1] = image[7];
	EWalkRight[2] = image[8];
	EWalkUp[0] = image[9];
	EWalkUp[1] = image[10];
	EWalkUp[2] = image[11];
	animeNum = 1;

	MadamWalk[0] = LoadSoundMem("sounds/madam/1.wav");
	MadamWalk[1] = LoadSoundMem("sounds/madam/2.wav");
	MadamWalk[2] = LoadSoundMem("sounds/madam/3.wav");
	MadamWalk[3] = LoadSoundMem("sounds/madam/4.wav");

	Eimage = image[0];
	move.Set(0, 0);
	enemy.Set(0, 0, MADAM_RANGE, 0);
	return 0;
}
int Son::Initialize() {
	LoadDivGraph("images/enemies/son/son.png", 12, 3, 4, 32, 32, image);
	EWalkDown[0] = image[0];
	EWalkDown[1] = image[1];
	EWalkDown[2] = image[2];
	EWalkLeft[0] = image[3];
	EWalkLeft[1] = image[4];
	EWalkLeft[2] = image[5];
	EWalkRight[0] = image[6];
	EWalkRight[1] = image[7];
	EWalkRight[2] = image[8];
	EWalkUp[0] = image[9];
	EWalkUp[1] = image[10];
	EWalkUp[2] = image[11];
	animeNum = 1;

	SonWalk[0] = LoadSoundMem("sounds/son/1.wav");
	SonWalk[1] = LoadSoundMem("sounds/son/2.wav");
	SonWalk[2] = LoadSoundMem("sounds/son/3.wav");
	SonWalk[3] = LoadSoundMem("sounds/son/4.wav");

	Eimage = image[0];
	move.Set(0, 0);
	enemy.Set(0, 0, SON_RANGE, 0);
	return 0;
}

Dot Son::GetDest(){
	return dest;
}
int Enemy::GetState() {
	return stateflag;
}
int Enemy::GetNextNum() {
	return nextNum;
}
int Husband::GetState() {
	return stateflag;
}
int Husband::GetNextNum() {
	return nextNum;
}


int Daughter::Initialize() {
	LoadDivGraph("images/enemies/daughter/daughter.png", 12, 3, 4, 32, 32, image);
	EWalkDown[0] = image[0];
	EWalkDown[1] = image[1];
	EWalkDown[2] = image[2];
	EWalkLeft[0] = image[3];
	EWalkLeft[1] = image[4];
	EWalkLeft[2] = image[5];
	EWalkRight[0] = image[6];
	EWalkRight[1] = image[7];
	EWalkRight[2] = image[8];
	EWalkUp[0] = image[9];
	EWalkUp[1] = image[10];
	EWalkUp[2] = image[11];
	animeNum = 1;

	DaughterWalk[0] = LoadSoundMem("sounds/daughter/1.wav");
	DaughterWalk[1] = LoadSoundMem("sounds/daughter/2.wav");
	DaughterWalk[2] = LoadSoundMem("sounds/daughter/3.wav");
	DaughterWalk[3] = LoadSoundMem("sounds/daughter/4.wav");

	Eimage = image[0];
	move.Set(0, 0);
	enemy.Set(0, 0, DAUGHTER_RANGE, 0);
	return 0;
}

Husband husband;
Madam madam;
Son son;
Daughter daughter;
int EnemyMngInitialize() {
	husband.Initialize();
	madam.Initialize();
	son.Initialize();
	daughter.Initialize();
	for (int i = 0; i < 27; i++) {
		DEST1[i].Set(ENEPOSI_1[2 * i], ENEPOSI_1[2 * i + 1]);
	}
	for (int i = 0; i < 20; i++) {
		DEST2[i].Set(ENEPOSI_2[2 * i], ENEPOSI_2[2 * i + 1]);
	}
	return 0;
}

int EnemyMngSet() {
	husband.Set(HUSBAND_HALF_SPEED,1);
	madam.Set(MADAM_HALF_SPEED, 1);
	son.Set(SON_HALF_SPEED, 2);
	daughter.Set(DAUGHTER_HALF_SPEED, 2);
	
	return 0;
}

int EnemyMngUpdata(Circle player,int floor,int count,SoundMng psound) {
	if (floor == 4) {
		husband.Set(HUSBAND_HALF_SPEED, 1);
		madam.Set(MADAM_HALF_SPEED, 1);
		if (son.Updata(player,2,SON_HALF_SPEED,SON_FULL_SPEED,0,count,psound)) {
			return 1;
		}
		if (daughter.Updata(player,2,DAUGHTER_HALF_SPEED,DAUGHTER_FULL_SPEED,1,count,psound)) {
			return 2;
		}
		if ((son.GetState() == 0 || son.GetState() == 1) && (daughter.GetState() == 0 || daughter.GetState() == 1)) {
			StopChaseBGM();
		}
	}
	else if (floor == 1) {
		son.Set(SON_HALF_SPEED, 2);
		daughter.Set(DAUGHTER_HALF_SPEED, 2);
		if (husband.Updata(player,1,HUSBAND_HALF_SPEED,HUSBAND_FULL_SPEED,2,count,psound)) {
			return 3;
		}
		if (madam.Updata(player,1,MADAM_HALF_SPEED,MADAM_FULL_SPEED,3,count,psound)) {
			return 4;
		}
		if ((husband.GetState() == 0 || husband.GetState() == 1) && (madam.GetState() == 0 || madam.GetState() == 1)) {
			StopChaseBGM();
		}
	}
	return 0;
}

int EnemyMngSoundDraw(Circle player, int count,int flag) {
	son.SoundDraw(player, count,flag);
	daughter.SoundDraw(player, count,flag);
	madam.SoundDraw(player, count,flag);
	husband.SoundDraw(player, count,flag);
	return 0;
}
int EnemyMngDraw(Dot player,int floor) {
	if (floor == 4) {
		son.Draw(player);
		daughter.Draw(player);
		//DrawFormatString(500, 0, RED, "SON_DRAWING");
		/*for (int i = 0; i < 20; i++) {
			DrawCircle(DEST2[i].Getx() + DISP_WIDTH / 2.0 - player.Getx(), DEST2[i].Gety() + DISP_HEIGHT / 2.0 - player.Gety(), ONPOINT, RED, 1);
		}*/
	}
	else if (floor == 1) {
		husband.Draw(player);
		madam.Draw(player);
		/*for (int i = 0; i < 27; i++) {
			DrawCircle(DEST1[i].Getx() + DISP_WIDTH / 2.0 - player.Getx(), DEST1[i].Gety() + DISP_HEIGHT / 2.0 - player.Gety(), 30, RED, 1);
		}*/
	}
	//DrawFormatString(300, 20, RED, "dest:(%5f,%5f)",son.GetDest().Getx(),son.GetDest().Gety());
	//DrawFormatString(300, 40, RED, "move:(%5f,%5f)", son.GetMove().Getx(), son.GetMove().Gety());
	//DrawFormatString(300, 60, RED, "stateflag:%d", husband.GetState());
	//DrawFormatString(300, 80, RED, "son:%d,s:%d", son.GetNextNum() + 1,son.GetState());
	//DrawFormatString(300, 100, RED, "daughter:%d,s:%d", daughter.GetNextNum() + 1,daughter.GetState());
	//DrawFormatString(300, 120, RED, "husband:%d", husband.GetNextNum() + 1);
	//DrawFormatString(300, 140, RED, "madam:%d", madam.GetNextNum() + 1);
	return 0;
}

/*-------������-------*/
int eram;
int PlaySonWalk() {
	eram = GetRand();
	PlaySoundMem(SonWalk[eram % 4], DX_PLAYTYPE_BACK);
	//DrawFormatString(0, 40, RED, "Sound!");
	return 0;
}
int PlayDaughterWalk() {
	eram = GetRand();
	PlaySoundMem(DaughterWalk[eram % 4], DX_PLAYTYPE_BACK);
	//DrawFormatString(0, 40, RED, "Sound!");
	return 0;
}
int PlayHusbandWalk() {
	eram = GetRand();
	PlaySoundMem(HusbandWalk[eram % 4], DX_PLAYTYPE_BACK);
	//DrawFormatString(0, 40, RED, "Sound!");
	return 0;
}
int PlayMadamWalk() {
	eram = GetRand();
	PlaySoundMem(MadamWalk[eram % 4], DX_PLAYTYPE_BACK);
	//DrawFormatString(0, 40, RED, "Sound!");
	return 0;
}
int yesESounds() {
	for (int i = 0; i < 4; i++) {
		ChangeVolumeSoundMem(255, SonWalk[i]);
		ChangeVolumeSoundMem(255, DaughterWalk[i]);
		ChangeVolumeSoundMem(255, MadamWalk[i]);
		ChangeVolumeSoundMem(255, HusbandWalk[i]);
	}
	return 0;
}
int noESounds() {
	for (int i = 0; i < 4; i++) {
		ChangeVolumeSoundMem(0, SonWalk[i]);
		ChangeVolumeSoundMem(0, DaughterWalk[i]);
		ChangeVolumeSoundMem(0, MadamWalk[i]);
		ChangeVolumeSoundMem(0, HusbandWalk[i]);
	}
	return 0;
}
