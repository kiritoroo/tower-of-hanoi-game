
//      ||    ||   ||||     ||    || |||||||| ||     //
//      ||    || ||    ||   ||||  || ||    || ||     //
//      |||||||| ||||||||   || || || ||    || ||     //
//      ||    || ||    ||   ||  |||| ||    || ||     //
//      ||    || ||    ||   ||   ||| |||||||| ||     //

#include<graphics.h>
#include<iostream>
#include<windows.h>

struct TOADO
{
	int x;
	int y;
};

struct KHOIDIA
{
	int left;
	int right;
	int top;
	int bottom;
	int kichThuoc;
	int viTriCot;
	int viTriStack;
	TOADO toaDoBlock;
	int chieuRongMotBen;
	int chieuDaiMotBen;
	int mauSac;
};

struct STACK
{
	int chiSo;
	TOADO toaDoStack;
};

struct KHOICOT
{
	TOADO toaDoCot;
	int chiSo;
	int left;
	int right;
	int top;
	int bottom;
	int mauSac;
	STACK stack[20];
};
struct KHOI
{
	int left;
	int right;
	int top;
	int bottom;
	int mauSac;
};


using namespace std;

int soDia = 3;
int page = 0;
int trangThaiStack[20][4];
int trangThaiChonBlock;
int soBuocDiChuyen;
int soBuocDiChuyenToiDa;
int auto_soBuocDiChuyen;
int doKho = 0;
int chiSoCot_autoDiChuyen=1;
int tocDo = 400;
TOADO toaDoGoc;
KHOICOT cot[4];
KHOIDIA block[20];
TOADO toaDoChuot;
KHOIDIA blockDuocChon;
KHOICOT *auto_cotBanDau;
KHOICOT *auto_cotChuyenDen;





KHOI khoiChoiMoi;
KHOI khoiQuyTac;
KHOI khoiThoatGame;
KHOI khoiLoadGame[5];
KHOI khoiTrangTri;
KHOI khoiQuayLai;
KHOI khoiWinGame;
KHOI khoiTiepTuc;
KHOI khoiTangBlock;
KHOI khoiGiamBlock;
KHOI khoiTangDoKho;
KHOI khoiGiamDoKho;
KHOI khoiHuongDan;



void taoToaDoChuot();
void hienThiToaDoChuot();

void HaNoi();
void test();
void newGame();
void menuGame();
void loadGame();

main()
{
	SetConsoleTitle("Ha Noi of my");
	HaNoi();
	initwindow(1000, 1000);
	HWND hWnd, hWndChild;
  	hWnd = FindWindow(NULL, "Windows BGI");
  	hWndChild = GetWindow(hWnd, GW_CHILD);
  	SendMessage((HWND) hWnd, WM_SETTEXT,0, (LPARAM)"Ha Noi of my");
  	
  	
	loadGame();
	getch();
	cleardevice();
	menuGame();
	
	
	getch();
	
}


void taoKhoiLoadGame();



//LOAD GAME
void loadGame()
{
	taoKhoiLoadGame();
}


//MENU GAME
void taoKhoiChoiMoi();
bool chonChoiMoi();
void taoKhoiQuyTac();
bool chonQuyTac();
void hienThiQuyTac();
void taoKhoiThoatGame();
bool chonThoatGame();
void taoKhoiQuayLai();
bool chonQuayLai();
void taoKhoiWinGame();
void taoKhoiTiepTuc();
bool chonTiepTuc();
void tuyChon();
bool chonTangBlock();
bool chonGiamBlock();
void chinhDoKho();
bool chonTangDoKho();
bool chonGiamDoKho();
void chinhSoBuocDiChuyenToiDa();
void taoKhoiHuongDan();
bool chonHuongDan();
void huongDan();

void menuGame()
{
	while(1)
	{
		setactivepage(page);
		setvisualpage(1-page);
		cleardevice();
		
		taoToaDoChuot();
		taoKhoiChoiMoi();
		taoKhoiQuyTac();
		taoKhoiThoatGame();		
		if(chonChoiMoi()==true)
		{
			soDia = 3;
			doKho = 0;
			chinhSoBuocDiChuyenToiDa();
			cleardevice();
			newGame();
		}
		if(chonQuyTac()==true)
		{
			cleardevice();
			hienThiQuyTac();
		}
		if(chonThoatGame()==true)
		{
			cleardevice();
			outtextxy(400,500,"See you late !");
			Sleep(0100);
			exit(0);
		}
		
		delay(5);
		page = 1-page;
	}
	
}


//INPUT GAME
void chonBlock();
void datBlock(KHOIDIA blockDuocChon);

void inputGame()
{
	taoToaDoChuot();
	hienThiToaDoChuot();
	chonBlock();
	datBlock(blockDuocChon);
}


//NEW GAME 
void taoToaDoCot();
void taoKichThuocCot();
void taoMauCotBanDau();
void veCot();
void taoToaDoStack();
void taoToaDoBlockBanDau();
void taoKichThuocBlock();
void taoMauBlockBanDau();
void veBlock();
void trangThaiStackBanDau();
void resetTrangThaiStack();
void hienThiTrangThaiStack();

void diChuyenBlock(int b, KHOICOT c);
bool dieuKienChonBlock(int b, KHOICOT c);
bool dieuKienDatBlock(int b, KHOICOT c);
void datBlockVaoStack(int b,KHOICOT c);

bool win();
bool lose();

void auto_taoMangDiChuyen(int n ,KHOICOT a, KHOICOT b, KHOICOT c);
void auto_taoSoBuocDiChuyen();
void auto_xuatMangDiChuyen();
void auto_diChuyenBlock(KHOICOT cotBanDau, KHOICOT cotChuyenDen);

void newGame()
{
	soDia = soDia;
	toaDoGoc.x = 200;
	toaDoGoc.y = 650 - soDia*20;
	trangThaiChonBlock = 0;
	soBuocDiChuyen = 0;
	
	taoToaDoCot();
	taoToaDoStack();
	trangThaiStackBanDau();
	taoKichThuocCot();
	taoMauCotBanDau();
	taoToaDoBlockBanDau();
	taoMauBlockBanDau();	
	
	test(); 
	  
	//VONG LAP GAME
	while(1)
	{
		setactivepage(page);
		setvisualpage(1-page);
		cleardevice();
		
		tuyChon();
		chinhDoKho();
		taoKhoiQuayLai();
		taoKhoiHuongDan();
		inputGame();
		veCot();
		taoKichThuocBlock();
		//veBlock();		
		if(chonTangBlock()==true)
		{
			if(soDia<15)
			{
				soDia = soDia + 1;
				chinhSoBuocDiChuyenToiDa();	
				Sleep(0200);
				newGame();
			}
			
		}
		if(chonGiamBlock()==true)
		{
			if(soDia>2)
			{
				soDia = soDia - 1;
				chinhSoBuocDiChuyenToiDa();	
				Sleep(0100);
				newGame();
			}
		}
		
		if(chonTangDoKho()==true)
		{
			if(doKho<2)
			{
				doKho ++;
				chinhSoBuocDiChuyenToiDa();	
				Sleep(0100);
				newGame();
			}
		}
		
		if(chonGiamDoKho()==true)
		{
			if(doKho>0)
			{
				doKho--;
				chinhSoBuocDiChuyenToiDa();		
				Sleep(0300);
				newGame();
			}
			
		}
		
		if(chonQuayLai()==true)
		{
			menuGame();
		}
		
		if(win()==true)
		{
			for(int i=1;i<=soDia;i++)
			{
				block[i].mauSac = 10;
			}
			taoToaDoChuot();
			taoKhoiWinGame();
			taoKhoiTiepTuc();
			if(chonTiepTuc()==true)
			{
				taoToaDoBlockBanDau();
				soBuocDiChuyen = 0;
			}
		}
		
		
		if(lose()==true)
		{
			taoToaDoChuot();
			taoKhoiWinGame();
			taoKhoiTiepTuc();
			if(chonTiepTuc()==true)
			{
				taoToaDoBlockBanDau();
				soBuocDiChuyen = 0;
			}
		}
		
		
		if(chonHuongDan()==true)
		{
			huongDan();	
		}
		
		
		
		delay(1);
		page = 1 - page;
	}
}









//KIEM TRA 
void xuatToaDoCot();
void xuatKichThuocCot();	
void xuatToaDoStack();
void xuatChiSoStack();

void test()
{	
//	xuatToaDoCot();	
//	xuatKichThuocCot();	
//	xuatToaDoStack();
//	xuatChiSoStack();
	cout<<endl;
}












//TAO TOA DO CHO COT
void taoToaDoCot()
{
	int khoangCachCacCot=0;
	for(int c=1;c<=3;c++)
	{
		cot[c].chiSo = c;
		cot[c].toaDoCot.x = toaDoGoc.x + khoangCachCacCot;
		cot[c].toaDoCot.y = toaDoGoc.y;
		khoangCachCacCot += 300;
	}
}
void xuatToaDoCot()
{
	cout<<"==========Toa do COT: "<<endl;
	for(int c=1;c<=3;c++)
	{
		cout<<"Cot: "<<cot[c].chiSo<<"  "<<"x: "<<cot[c].toaDoCot.x<<"  "<<"y: "<<cot[c].toaDoCot.y<<endl;
	}
	cout<<endl;
}


//TAO KICK THUOC CHO COT
void taoKichThuocCot()
{
	for(int c=1;c<=3;c++)
	{
		cot[c].left = cot[c].toaDoCot.x - 10;
		cot[c].right = cot[c].toaDoCot.x + 10;
		cot[c].top = cot[c].toaDoCot.y -30;
		cot[c].bottom = cot[c].toaDoCot.y + 30*soDia;
	}
}
void xuatKichThuocCot()
{
	
	cout<<"==========Kich thuoc COT: "<<endl;
	for(int c=1;c<=3;c++)
	{
		cout<<"Cot: "<<cot[c].chiSo<<" "<<"Left: "<<cot[c].left<<" "<<"Top: "<<cot[c].top<<" "<<"Right: "<<cot[c].right<<" "<<"Bottom: "<<cot[c].bottom<<endl;
	}
	cout<<endl;
}


//VE COT
void taoMauCotBanDau()
{
	for(int c=1;c<=3;c++)
	{
		cot[c].mauSac = 13;
	}
}
void veCot()
{
	for(int c=1;c<=3;c++)
	{
		setfillstyle(USER_FILL,cot[c].mauSac);
		bar(cot[c].left, cot[c].top, cot[c].right, cot[c].bottom);
		setfillstyle(USER_FILL,15);
	}
}




//TAO TOA DO CHO STACK 
void taoToaDoStack()
{
	int khoangCachCacStack;
	for(int c=1;c<=3;c++)
	{
		khoangCachCacStack = 0;
		for(int s=1;s<=soDia;s++)
		{
			cot[c].stack[s].chiSo = s;
			cot[c].stack[s].toaDoStack.x = cot[c].toaDoCot.x;
			cot[c].stack[s].toaDoStack.y = cot[c].toaDoCot.y + khoangCachCacStack ;
			
			if(c==2)
			{
				khoangCachCacStack +=32;
			}
			else
			{
				khoangCachCacStack += 30;	
			}
		}
	}
}
void xuatToaDoStack()
{
	cout<<"==========Toa do STACK"<<endl;
	for(int c=1;c<=3;c++)
	{
		cout<<"Cot: "<<cot[c].chiSo<<endl;
		for(int s=1;s<=soDia;s++)
		{
			cout<<"Stack: "<<cot[c].stack[s].chiSo<<"  "<<"x: "<<cot[c].stack[s].toaDoStack.x<<"  "<<"y: "<<cot[c].stack[s].toaDoStack.y<<endl;
		}
		cout<<endl;
	}
	cout<<endl;
}
void xuatChiSoStack()
{
	cout<<"==========Chi so STACK"<<endl;
	for(int s=1;s<=soDia;s++)
	{
		for(int c=1;c<=3;c++)
		{
			cout<<cot[c].stack[s].chiSo<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
};

//TRANGTHAISTACKBANDAU
void trangThaiStackBanDau()
{
	for(int s=1;s<=soDia;s++)
	{
		for(int c=1;c<=3;c++)
		{
			trangThaiStack[0][c] = 0;
			trangThaiStack[s][c] = 0;
			trangThaiStack[soDia+1][c] = 100;
		}
	}
}

//RESET TRANG THAI STACK VE 0
void resetTrangThaiStack()
{
	for(int s=1;s<=soDia;s++)
	{
		for(int c=1;c<=3;c++)
		{
			trangThaiStack[s][c] = 0;
		}
	}
}

//HIEN THI TRANG THAI STACK
void hienThiTrangThaiStack()
{
	settextstyle(2,0,6);
	int x;
	int y = 100;
	char a[100];
	for(int s=1;s<=soDia;s++)
	{
		x=100;
		for(int c=1;c<=3;c++)
		{
			sprintf(a,"%d", trangThaiStack[s][c]);
			outtextxy(x,y,a);
			x+=20;
		}
		y+=20;
	}
}






//TAO TOA DO BAN DAU CHO BLOCK
void taoToaDoBlockBanDau()
{
	for(int b=1;b<=soDia;b++)
	{
		block[b].viTriCot = cot[1].chiSo;
		block[b].viTriStack = cot[1].stack[b].chiSo;
		block[b].toaDoBlock.x = cot[1].toaDoCot.x;
		block[b].toaDoBlock.y = cot[1].stack[b].toaDoStack.y;
	}
	
}

//TAO KICH THUOC CHO BLOCK
void taoKichThuocBlock()
{
	resetTrangThaiStack();
	for(int b=1;b<=soDia;b++)
	{
		block[b].kichThuoc = b;
		block[b].chieuDaiMotBen = 10;
		block[b].chieuRongMotBen = (b*30)/2;
		block[b].left = block[b].toaDoBlock.x - block[b].chieuRongMotBen;
		block[b].right = block[b].toaDoBlock.x + block[b].chieuRongMotBen;
		block[b].top = block[b].toaDoBlock.y - block[b].chieuDaiMotBen;
		block[b].bottom = block[b].toaDoBlock.y + block[b].chieuDaiMotBen;
		
		trangThaiStack[block[b].viTriStack][block[b].viTriCot] = block[b].kichThuoc;
	}
	
	hienThiTrangThaiStack();
	veBlock();
}

//TAO MAU BAN DAU CHO BLOCK
void taoMauBlockBanDau()
{
	for(int b=1;b<=soDia;b++)
	{
		block[b].mauSac = 15;
	}
}

//VE BLOCK
void veBlock()
{
	for(int b=1;b<=soDia;b++)
	{
		setfillstyle(USER_FILL, block[b].mauSac);
		bar(block[b].left, block[b].top, block[b].right, block[b].bottom);
		setfillstyle(USER_FILL, 15);	
	}
}


//DI CHUYEN BLOCK QUA COT KHAC
void diChuyenBlock(int b, KHOICOT c)
{
	if(dieuKienChonBlock(b,c)==true && dieuKienDatBlock(b,c)==true)
	{
		block[b].viTriCot = c.chiSo;
		block[b].toaDoBlock.x = c.toaDoCot.x;
		//block[b].toaDoBlock.y = c.toaDoCot.y;
		datBlockVaoStack(b,c);
		trangThaiStack[block[b].viTriStack][c.chiSo] = block[b].kichThuoc;
		soBuocDiChuyen++;
	}
}

//DIEU KIEN CHON COT
bool dieuKienChonBlock(int b, KHOICOT c)
{
	if(trangThaiStack[block[b].viTriStack-1][block[b].viTriCot]==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//DIEU KIEN DAT BLOCK
bool dieuKienDatBlock(int b, KHOICOT c)
{
	for(int s=1;s<=soDia;s++)
	{
		if(trangThaiStack[s][c.chiSo] !=0)
		{
			if(trangThaiStack[s][c.chiSo] > block[b].kichThuoc)
			{
				return true;
				break;
			}
			else
			{
				return false;
				break;
			}
		}
	}
}

//DI CHUYEN BLOCK VAO CAC STACK
void datBlockVaoStack(int b,KHOICOT c)
{
	for(int s=soDia;s>0;s--)
	{
		if(trangThaiStack[s][c.chiSo]==0 && trangThaiStack[s+1][c.chiSo]>block[b].kichThuoc)
		{
			block[b].viTriStack = s;
			block[b].toaDoBlock.x = c.stack[s].toaDoStack.x;
			block[b].toaDoBlock.y =  c.stack[s].toaDoStack.y;
			break;
		}
	}
}

//DIEU KIEN WIN
bool win()
{
	
	for(int s=1;s<=soDia;s++)
	{
		if(trangThaiStack[s][3] != s)
		{
			return false;
		}
	}
	
	return true;
	
}
//DIEU KIEN LOSE
bool lose()
{
	if(soBuocDiChuyen==soBuocDiChuyenToiDa && win()==false)
	{
		return true;
	}
	else
	{
		return false;
	}
}














//TAO TOA DO CHUOT
void taoToaDoChuot()
{
	POINT pos;
	GetCursorPos(&pos);
	toaDoChuot.x = pos.x - 8;
	toaDoChuot.y = pos.y - 30; 
}

//HIEN THI TOA DO CHUOT
void hienThiToaDoChuot()
{
//	char a[10];
//	sprintf(a,"%d",toaDoChuot.x);
//	outtextxy(200,100,a);
//	
//	char b[10];
//	sprintf(b,"%d",toaDoChuot.y);
//	outtextxy(250,100,b);
}

//CHON BLOCK
void chonBlock()
{
	if(GetAsyncKeyState(VK_LBUTTON))
	{
		for(int b=1;b<=soDia;b++)
		{
			if(toaDoChuot.x>block[b].left && toaDoChuot.x<block[b].right && toaDoChuot.y>block[b].top && toaDoChuot.y<block[b].bottom)
			{
				if(dieuKienChonBlock(block[b].kichThuoc,cot[block[b].viTriCot])==true)
				{
					trangThaiChonBlock = 1;
					blockDuocChon = block[b];
//					char a[10];
//					sprintf(a,"%d",blockDuocChon.kichThuoc);
//					outtextxy(200,150,a);
				
					block[b].mauSac = 10;
				}
				else
				{
					block[b].mauSac = 4;
					trangThaiChonBlock = 0;
				}
				
			}
			else
			{
				block[b].mauSac = 15;
			}
		}
	}
}

//DAT BLOCK
void datBlock(KHOIDIA blockDuocChon)
{
	if(trangThaiChonBlock == 1)
	{
		if(GetAsyncKeyState(VK_LBUTTON))
		{
			for(int c=1;c<=3;c++)
			{
				if(toaDoChuot.x>cot[c].left-20 && toaDoChuot.x<cot[c].right+20 && toaDoChuot.y>cot[c].top && toaDoChuot.y<cot[c].bottom)
				{
					diChuyenBlock(blockDuocChon.kichThuoc,cot[cot[c].chiSo]);
					trangThaiChonBlock ==0;	
				}	
			}
		}	
	}
	
}









void taoKhoiLoadGame()
{
	int x = 350;
	int y = 600;
	int kichThuoc = 20;
	int khoangCachCacKhoi=0;
	for(int i=0;i<5;i++)
	{
		khoiLoadGame[i].left = x+khoangCachCacKhoi;
		khoiLoadGame[i].right = x+kichThuoc+khoangCachCacKhoi;
		khoiLoadGame[i].top = y;
		khoiLoadGame[i].bottom = y+kichThuoc;
		khoangCachCacKhoi+=50;
	}
	
	khoiLoadGame[5].left = x-10;
	khoiLoadGame[5].right = x+kichThuoc+10;
	khoiLoadGame[5].top = y-10;
	khoiLoadGame[5].bottom = y+kichThuoc+10;
	int i=0;
	while(i<55)
	{		
		khoangCachCacKhoi =0;
		for(int i=0;i<5;i++)
		{
			for(int i=0;i<5;i++)
			{
				setfillstyle(USER_FILL,15);
				bar(khoiLoadGame[i].left, khoiLoadGame[i].top, khoiLoadGame[i].right, khoiLoadGame[i].bottom);
				
				settextstyle(2,0,6);
				outtextxy(x,y-40,"LOADING");
				settextstyle(2,0,6);
				
			}
			setfillstyle(USER_FILL,15);
			
			setfillstyle(USER_FILL,10);
			bar(khoiLoadGame[5].left+khoangCachCacKhoi, khoiLoadGame[5].top, khoiLoadGame[5].right+khoangCachCacKhoi, khoiLoadGame[5].bottom);
			khoangCachCacKhoi+=50;
			Sleep(0100);
			cleardevice();
		}
		i++;
		delay(1);
	}
	
			for(int i=0;i<5;i++)
			{
				setfillstyle(USER_FILL,15);
				bar(khoiLoadGame[i].left, khoiLoadGame[i].top, khoiLoadGame[i].right, khoiLoadGame[i].bottom);
				
				settextstyle(2,0,6);
				outtextxy(x,y-40,"LOADING");
				settextstyle(2,0,6);
			}
		khoangCachCacKhoi =0;
		for(int i=0;i<5;i++)
		{
			setfillstyle(USER_FILL,10);
			bar(khoiLoadGame[5].left+khoangCachCacKhoi, khoiLoadGame[5].top, khoiLoadGame[5].right+khoangCachCacKhoi, khoiLoadGame[5].bottom);
			khoangCachCacKhoi+=50;
			Sleep(0200);
		}
		
	x = 350;
	y = 0;
	while(y<=250)
	{
		setactivepage(page);
		setvisualpage(page-1);
		cleardevice();
		settextstyle(2,0,20);
		outtextxy(x,y,"TOWER");
		outtextxy(x,y+50,"OF");
		outtextxy(x,y+100,"HANOI");
		settextstyle(2,0,6);
		y=y+10;	
		
		delay(10);
		page = 1 - page;
	}
	Sleep(0500);
	while(x>100)
	{
		setactivepage(page);
		setvisualpage(page-1);
		cleardevice();
		
		setcolor(15);
		settextstyle(2,0,20);
		outtextxy(x+10,y+10,"TOWER"); 
		outtextxy(x+10,y+50+10,"OF");
		outtextxy(x+10,y+100+10,"HANOI");
		settextstyle(2,0,6);
		
		setcolor(10);
		settextstyle(2,0,20);
		outtextxy(x,y,"TOWER");
		outtextxy(x,y+50,"OF");
		outtextxy(x,y+100,"HANOI");
		settextstyle(2,0,6);
		setcolor(15);
		
		
		x=x-10;	
		
		delay(5);
		page = 1 - page;
	}
	
	
	
	i=0;
	x = 600;
	y = 400;
	khoangCachCacKhoi = 0;
	kichThuoc=0;
	
	khoiTrangTri.left = x-200;
	khoiTrangTri.right = x+200;
	khoiTrangTri.top = y-10;
	khoiTrangTri.bottom = y+10;
	setfillstyle(USER_FILL,10);
	while(i<10)
	{
		bar(khoiTrangTri.left+kichThuoc, khoiTrangTri.top-khoangCachCacKhoi, khoiTrangTri.right-kichThuoc, khoiTrangTri.bottom-khoangCachCacKhoi-5);
		khoangCachCacKhoi+=20;
		kichThuoc+=20;
		i++;
		delay(0100);
	}
	
	settextstyle(2,0,8);
	outtextxy(280,800,"Nhan nut bat ki de tiep tuc !");
	settextstyle(2,0,6);
	
	
}




void taoKhoiChoiMoi()
{
	khoiChoiMoi.left = 300;
	khoiChoiMoi.right = 650;
	khoiChoiMoi.top = 200;
	khoiChoiMoi.bottom = 300;
	
	setfillstyle(HATCH_FILL,YELLOW);
	bar(khoiChoiMoi.left, khoiChoiMoi.top, khoiChoiMoi.right+10, khoiChoiMoi.bottom+10);
	setfillstyle(USER_FILL,WHITE);
	bar(khoiChoiMoi.left, khoiChoiMoi.top, khoiChoiMoi.right, khoiChoiMoi.bottom);
	
	settextstyle(2,0,10);
	setcolor(khoiChoiMoi.mauSac);
	outtextxy(360,220,"CHOI MOI");
	settextstyle(2,0,6);
	setcolor(15);
}

bool chonChoiMoi()
{
	if(toaDoChuot.x>khoiChoiMoi.left && toaDoChuot.x<khoiChoiMoi.right && toaDoChuot.y>khoiChoiMoi.top && toaDoChuot.y<khoiChoiMoi.bottom)
	{
		khoiChoiMoi.mauSac = 10;
	}
	else
	{
		khoiChoiMoi.mauSac = 15;
	}
	if(GetAsyncKeyState(VK_LBUTTON))
	{
		if(toaDoChuot.x>khoiChoiMoi.left && toaDoChuot.x<khoiChoiMoi.right && toaDoChuot.y>khoiChoiMoi.top && toaDoChuot.y<khoiChoiMoi.bottom)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void taoKhoiQuyTac()
{
	khoiQuyTac.left = 300;
	khoiQuyTac.right = 650;
	khoiQuyTac.top = 350;
	khoiQuyTac.bottom = 450;
	
	setfillstyle(HATCH_FILL,YELLOW);
	bar(khoiQuyTac.left, khoiQuyTac.top, khoiQuyTac.right+10, khoiQuyTac.bottom+10);
	setfillstyle(USER_FILL,WHITE);
	bar(khoiQuyTac.left, khoiQuyTac.top, khoiQuyTac.right, khoiQuyTac.bottom);
	
	settextstyle(2,0,10);
	setcolor(khoiQuyTac.mauSac);
	outtextxy(360,380,"LUAT CHOI");
	settextstyle(2,0,6);
	setcolor(15);
}

bool chonQuyTac()
{
	if(toaDoChuot.x>khoiQuyTac.left && toaDoChuot.x<khoiQuyTac.right && toaDoChuot.y>khoiQuyTac.top && toaDoChuot.y<khoiQuyTac.bottom)
	{
		khoiQuyTac.mauSac = 10;
	}
	else
	{
		khoiQuyTac.mauSac = 15;
	}
	if(GetAsyncKeyState(VK_LBUTTON))
	{
		if(toaDoChuot.x>khoiQuyTac.left && toaDoChuot.x<khoiQuyTac.right && toaDoChuot.y>khoiQuyTac.top && toaDoChuot.y<khoiQuyTac.bottom)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void hienThiQuyTac()
{
	while(1)
	{
		taoToaDoChuot();
		setactivepage(page);
		setvisualpage(1 - page);
		cleardevice();
		
		taoKhoiQuayLai();
		settextstyle(2,0,6);
		outtextxy(200,200,"Moi lan chi co the di chuyen mot dia tu cot nay sang cot khac.");
		outtextxy(200,250,"Chi duoc di chuyen dia nam tren cung.");
		outtextxy(200,300,"Dia co kich thuoc lon hon khong the duoc dat len dia co kich thuoc nho hon.");
		setcolor(LIGHTCYAN);
		settextstyle(2,0,6);
		outtextxy(200,400,"Ban chien thang khi tat ca cac dia duoc chuyen sang cot thu 3");
		setcolor(WHITE);
		settextstyle(2,0,6);
		
		if(chonQuayLai()==true)
		{
			break;
		}
		delay(1);
		page = 1- page;	
	}
}

void taoKhoiThoatGame()
{
	khoiThoatGame.left = 300;
	khoiThoatGame.right = 650;
	khoiThoatGame.top = 500;
	khoiThoatGame.bottom = 600;
	
	setfillstyle(HATCH_FILL,YELLOW);
	bar(khoiThoatGame.left, khoiThoatGame.top, khoiThoatGame.right+10, khoiThoatGame.bottom+10);
	setfillstyle(USER_FILL,WHITE);
	bar(khoiThoatGame.left, khoiThoatGame.top, khoiThoatGame.right, khoiThoatGame.bottom);
	
	settextstyle(2,0,10);
	setcolor(khoiThoatGame.mauSac);
	outtextxy(320,520,"THOAT GAME");
	settextstyle(2,0,6);
	setcolor(15);
}
bool chonThoatGame()
{
	if(toaDoChuot.x>khoiThoatGame.left && toaDoChuot.x<khoiThoatGame.right && toaDoChuot.y>khoiThoatGame.top && toaDoChuot.y<khoiThoatGame.bottom)
	{
		khoiThoatGame.mauSac = 10;
	}
	else
	{
		khoiThoatGame.mauSac = 15;
	}
	if(GetAsyncKeyState(VK_LBUTTON))
	{
		if(toaDoChuot.x>khoiThoatGame.left && toaDoChuot.x<khoiThoatGame.right && toaDoChuot.y>khoiThoatGame.top && toaDoChuot.y<khoiThoatGame.bottom)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void taoKhoiQuayLai()
{
	khoiQuayLai.left = 20;
	khoiQuayLai.right = 150;
	khoiQuayLai.top = 20;
	khoiQuayLai.bottom = 60;
	
	setfillstyle(HATCH_FILL,10);
	bar(khoiQuayLai.left, khoiQuayLai.top, khoiQuayLai.right+5, khoiQuayLai.bottom+5);
	setfillstyle(USER_FILL,WHITE);
	bar(khoiQuayLai.left, khoiQuayLai.top, khoiQuayLai.right, khoiQuayLai.bottom);
	
	settextstyle(2,0,6);
	setcolor(khoiQuayLai.mauSac);
	outtextxy(50,30,"Quay Lai");
	settextstyle(2,0,6);
	setcolor(15);
}
bool chonQuayLai()
{
	if(toaDoChuot.x>khoiQuayLai.left && toaDoChuot.x<khoiQuayLai.right && toaDoChuot.y>khoiQuayLai.top && toaDoChuot.y<khoiQuayLai.bottom)
	{
		khoiQuayLai.mauSac = 10;
	}
	else
	{
		khoiQuayLai.mauSac = 15;
	}
	if(GetAsyncKeyState(VK_LBUTTON))
	{
		if(toaDoChuot.x>khoiQuayLai.left && toaDoChuot.x<khoiQuayLai.right && toaDoChuot.y>khoiQuayLai.top && toaDoChuot.y<khoiQuayLai.bottom)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}


void taoKhoiWinGame()
{
	khoiWinGame.left = 200;
	khoiWinGame.right = 800;
	khoiWinGame.top = 400;
	khoiWinGame.bottom = 600;
	
	setfillstyle(USER_FILL,15);
	bar(khoiWinGame.left, khoiWinGame.top, khoiWinGame.right+10, khoiWinGame.bottom+10);
	setfillstyle(USER_FILL,WHITE);
	
	
	if(win()==true)
	{
		settextstyle(2,0,10);
		outtextxy(350,450,"Ban lam rat tot !");
		settextstyle(2,0,6);
	}
	else
	{
		settextstyle(2,0,10);
		outtextxy(320,450,"Thu lai nao, co len!");
		settextstyle(2,0,6);
	}
	
		
	
		
}


void taoKhoiTiepTuc()
{
	khoiTiepTuc.left = 400;
	khoiTiepTuc.right = 600;
	khoiTiepTuc.top = 500;
	khoiTiepTuc.bottom = 550;
	
	setfillstyle(USER_FILL,khoiTiepTuc.mauSac);
	bar(khoiTiepTuc.left, khoiTiepTuc.top, khoiTiepTuc.right+10, khoiTiepTuc.bottom+10);
	setfillstyle(USER_FILL,15);
	
	settextstyle(2,0,8);
	setcolor(khoiTiepTuc.mauSac);
	outtextxy(420,520,"TIEP TUC");
	settextstyle(2,0,6);
	setcolor(15);
}


bool chonTiepTuc()
{
	if(toaDoChuot.x>khoiTiepTuc.left && toaDoChuot.x<khoiTiepTuc.right && toaDoChuot.y>khoiTiepTuc.top && toaDoChuot.y<khoiTiepTuc.bottom)
	{
		if(win()==true)
		{
			khoiTiepTuc.mauSac = 10;	
		}
		else
		{
			khoiTiepTuc.mauSac = 12;
		}
	}
	else
	{
		if(win()==true)
		{
			khoiTiepTuc.mauSac = 2;
		}
		else
		{
			khoiTiepTuc.mauSac = 4;
		}
	}
	if(GetAsyncKeyState(VK_LBUTTON))
	{
		if(toaDoChuot.x>khoiTiepTuc.left && toaDoChuot.x<khoiTiepTuc.right && toaDoChuot.y>khoiTiepTuc.top && toaDoChuot.y<khoiTiepTuc.bottom)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}




void tuyChon()
{
	int y = 0;
	int x = 100;
	khoiTangBlock.left = 500+x;
	khoiTangBlock.right = 600+x;
	khoiTangBlock.top = 100+y;
	khoiTangBlock.bottom = 140+y;
	
	setfillstyle(HATCH_FILL,10);
	bar(khoiTangBlock.left, khoiTangBlock.top, khoiTangBlock.right+5, khoiTangBlock.bottom+5);
	setfillstyle(USER_FILL,WHITE);
	bar(khoiTangBlock.left, khoiTangBlock.top, khoiTangBlock.right, khoiTangBlock.bottom);
	
	settextstyle(2,0,6);
	setcolor(khoiTangBlock.mauSac);
	outtextxy(505+x,110+y,"Tang Block");
	settextstyle(2,0,6);
	setcolor(15);
	
	
	
	khoiGiamBlock.left = 650+x;
	khoiGiamBlock.right = 750+x;
	khoiGiamBlock.top = 100+y;
	khoiGiamBlock.bottom = 140+y;
	
	setfillstyle(HATCH_FILL,10);
	bar(khoiGiamBlock.left, khoiGiamBlock.top, khoiGiamBlock.right+5, khoiGiamBlock.bottom+5);
	setfillstyle(USER_FILL,WHITE);
	bar(khoiGiamBlock.left, khoiGiamBlock.top, khoiGiamBlock.right, khoiGiamBlock.bottom);
	
	settextstyle(2,0,6);
	setcolor(khoiGiamBlock.mauSac);
	outtextxy(655+x,110+y,"Giam Block");
	settextstyle(2,0,6);
	setcolor(15);
	
	outtextxy(500+x,160+y,"So Block hien tai: ");
	char a[10];
	sprintf(a,"%d", soDia);
	outtextxy(650+x,160+y,a);
	
	outtextxy(500+x,180+y,"So buoc da di chuyen: ");
	char b[10];
	sprintf(b,"%d", soBuocDiChuyen);
	if(win()==true)
	{
		setcolor(10);
	}
	if(lose()==true)
	{
		setcolor(RED);
	}
	outtextxy(700+x,180+y,b);
	setcolor(WHITE);
}


bool chonTangBlock()
{
	if(toaDoChuot.x>khoiTangBlock.left && toaDoChuot.x<khoiTangBlock.right && toaDoChuot.y>khoiTangBlock.top && toaDoChuot.y<khoiTangBlock.bottom)
	{
		khoiTangBlock.mauSac = 10;
	}
	else
	{
		khoiTangBlock.mauSac = 15;
	}
	if(GetAsyncKeyState(VK_LBUTTON))
	{
		if(toaDoChuot.x>khoiTangBlock.left && toaDoChuot.x<khoiTangBlock.right && toaDoChuot.y>khoiTangBlock.top && toaDoChuot.y<khoiTangBlock.bottom)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}


bool chonGiamBlock()
{
	if(toaDoChuot.x>khoiGiamBlock.left && toaDoChuot.x<khoiGiamBlock.right && toaDoChuot.y>khoiGiamBlock.top && toaDoChuot.y<khoiGiamBlock.bottom)
	{
		khoiGiamBlock.mauSac = 10;
	}
	else
	{
		khoiGiamBlock.mauSac = 15;
	}
	if(GetAsyncKeyState(VK_LBUTTON))
	{
		if(toaDoChuot.x>khoiGiamBlock.left && toaDoChuot.x<khoiGiamBlock.right && toaDoChuot.y>khoiGiamBlock.top && toaDoChuot.y<khoiGiamBlock.bottom)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}







void chinhDoKho()
{
	int y = 0;
	int x = -250;
	
	khoiTangDoKho.left = 500+x;
	khoiTangDoKho.right = 600+x;
	khoiTangDoKho.top = 100+y;
	khoiTangDoKho.bottom = 140+y;
	
	setfillstyle(HATCH_FILL,10);
	bar(khoiTangDoKho.left, khoiTangDoKho.top, khoiTangDoKho.right+5, khoiTangDoKho.bottom+5);
	setfillstyle(USER_FILL,WHITE);
	bar(khoiTangDoKho.left, khoiTangDoKho.top, khoiTangDoKho.right, khoiTangDoKho.bottom);
	
	settextstyle(2,0,6);
	setcolor(khoiTangDoKho.mauSac);
	outtextxy(505+x,110+y,"Tang do kho");
	settextstyle(2,0,6);
	setcolor(15);
	
	
	
	khoiGiamDoKho.left = 650+x;
	khoiGiamDoKho.right = 750+x;
	khoiGiamDoKho.top = 100+y;
	khoiGiamDoKho.bottom = 140+y;
	
	setfillstyle(HATCH_FILL,10);
	bar(khoiGiamDoKho.left, khoiGiamDoKho.top, khoiGiamDoKho.right+5, khoiGiamDoKho.bottom+5);
	setfillstyle(USER_FILL,WHITE);
	bar(khoiGiamDoKho.left, khoiGiamDoKho.top, khoiGiamDoKho.right, khoiGiamDoKho.bottom);
	
	settextstyle(2,0,6);
	setcolor(khoiGiamDoKho.mauSac);
	outtextxy(655+x,110+y,"Giam do kho");
	settextstyle(2,0,6);
	setcolor(15);
	
	outtextxy(500+x,160+y,"Do kho hien tai:  ");
	if(doKho == 2)
	{
		outtextxy(650+x,160+y,"Max");
	}
	else
	{
		char a[10];
		sprintf(a,"%d", doKho);
		outtextxy(650+x,160+y,a);
	}
	
	
	outtextxy(500+x,180+y,"So buoc di chuyen toi da:  ");
	if(doKho == 0)
	{
		outtextxy(720+x,180+y,"oo");
	}
	else
	{
		char b[10];
		sprintf(b,"%d", soBuocDiChuyenToiDa);
		outtextxy(720+x,180+y,b);
	}
	
}


bool chonTangDoKho()
{
	if(toaDoChuot.x>khoiTangDoKho.left && toaDoChuot.x<khoiTangDoKho.right && toaDoChuot.y>khoiTangDoKho.top && toaDoChuot.y<khoiTangDoKho.bottom)
	{
		khoiTangDoKho.mauSac = 10;
	}
	else
	{
		khoiTangDoKho.mauSac = 15;
	}
	if(GetAsyncKeyState(VK_LBUTTON))
	{
		if(toaDoChuot.x>khoiTangDoKho.left && toaDoChuot.x<khoiTangDoKho.right && toaDoChuot.y>khoiTangDoKho.top && toaDoChuot.y<khoiTangDoKho.bottom)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}


bool chonGiamDoKho()
{
	if(toaDoChuot.x>khoiGiamDoKho.left && toaDoChuot.x<khoiGiamDoKho.right && toaDoChuot.y>khoiGiamDoKho.top && toaDoChuot.y<khoiGiamDoKho.bottom)
	{
		khoiGiamDoKho.mauSac = 10;
	}
	else
	{
		khoiGiamDoKho.mauSac = 15;
	}
	if(GetAsyncKeyState(VK_LBUTTON))
	{
		if(toaDoChuot.x>khoiGiamDoKho.left && toaDoChuot.x<khoiGiamDoKho.right && toaDoChuot.y>khoiGiamDoKho.top && toaDoChuot.y<khoiGiamDoKho.bottom)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void chinhSoBuocDiChuyenToiDa()
{
	if(doKho == 0)
	{
		soBuocDiChuyenToiDa = 1000000;
	}
	if(doKho == 1)
	{
		if(soDia==2)
		{
			soBuocDiChuyenToiDa = 3*2;
		}
		if(soDia==3)
		{
			soBuocDiChuyenToiDa =7*2;
		}
		if(soDia>3)
		{
			soBuocDiChuyenToiDa = 7;
			for(int i=4;i<=soDia;i++)
			{
				soBuocDiChuyenToiDa = soBuocDiChuyenToiDa*2;
				soBuocDiChuyenToiDa+=1;
			}
			soBuocDiChuyenToiDa *=2;
		}
	}
	if(doKho == 2)
	{
		if(soDia==2)
		{
			soBuocDiChuyenToiDa = 3;
		}
		if(soDia==3)
		{
			soBuocDiChuyenToiDa =7;
		}
		if(soDia>3)
		{
			soBuocDiChuyenToiDa = 7;
			for(int i=4;i<=soDia;i++)
			{
				soBuocDiChuyenToiDa = soBuocDiChuyenToiDa*2;
				soBuocDiChuyenToiDa+=1;
			}
		}
		
	}
}

void taoKhoiHuongDan()
{
	khoiHuongDan.left = 250;
	khoiHuongDan.right = 350;
	khoiHuongDan.top = 230;
	khoiHuongDan.bottom = 280;
	
	setfillstyle(HATCH_FILL,10);
	bar(khoiHuongDan.left, khoiHuongDan.top, khoiHuongDan.right+5, khoiHuongDan.bottom+5);
	setfillstyle(USER_FILL,WHITE);
	bar(khoiHuongDan.left, khoiHuongDan.top, khoiHuongDan.right, khoiHuongDan.bottom);
	
	settextstyle(2,0,6);
	setcolor(khoiHuongDan.mauSac);
	outtextxy(260,240,"Huong dan");
	settextstyle(2,0,6);
	setcolor(15);
}

bool chonHuongDan()
{
	if(toaDoChuot.x>khoiHuongDan.left && toaDoChuot.x<khoiHuongDan.right && toaDoChuot.y>khoiHuongDan.top && toaDoChuot.y<khoiHuongDan.bottom)
	{
		khoiHuongDan.mauSac = 10;
	}
	else
	{
		khoiHuongDan.mauSac = 15;
	}
	if(GetAsyncKeyState(VK_LBUTTON))
	{
		if(toaDoChuot.x>khoiHuongDan.left && toaDoChuot.x<khoiHuongDan.right && toaDoChuot.y>khoiHuongDan.top && toaDoChuot.y<khoiHuongDan.bottom)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void huongDan()
{
	chiSoCot_autoDiChuyen = 1;
	auto_taoSoBuocDiChuyen();
	auto_cotBanDau = new KHOICOT[auto_soBuocDiChuyen+1];
	auto_cotChuyenDen = new KHOICOT[auto_soBuocDiChuyen+1];
	
	auto_taoMangDiChuyen(soDia,cot[1],cot[2],cot[3]);
	//auto_xuatMangDiChuyen();
	
	chiSoCot_autoDiChuyen = 1;
while(1)
{	
	setactivepage(page);
	setvisualpage(1-page);
	while(1)
	{	
		setactivepage(page);
		setvisualpage(1-page);
		cleardevice();
		
		veCot();
		
		if(win()==true)
		{
			break;
		}
		
		auto_diChuyenBlock(auto_cotBanDau[chiSoCot_autoDiChuyen], auto_cotChuyenDen[chiSoCot_autoDiChuyen]);
		chiSoCot_autoDiChuyen++;
		taoKichThuocBlock();
		if(soDia<3)
		{
			Sleep(tocDo+200); 
		}
		if(soDia<5)
		{
			Sleep(tocDo);	
		}	
		else if(soDia<7)
		{
			Sleep(tocDo-200);
		}
		
		delay(1);
		page = 1 -page;
	}
	
	veCot();
	taoKichThuocBlock();		
	taoToaDoChuot();
	taoKhoiTiepTuc();
	if(chonTiepTuc()==true)
	{
		newGame();
		break;
	}
	
	delay(1);
	page = 1 -page;
}
	
	
	delete []auto_cotBanDau;
	delete []auto_cotChuyenDen;
}




//AUTO HA NOI
void auto_taoMangDiChuyen(int n ,KHOICOT a, KHOICOT b, KHOICOT c)
{
    if(n==1){
    	auto_cotBanDau[chiSoCot_autoDiChuyen] = a;
    	auto_cotChuyenDen[chiSoCot_autoDiChuyen] = c;
    	chiSoCot_autoDiChuyen++;
        return;
    }
    auto_taoMangDiChuyen(n-1,a,c,b);
    auto_taoMangDiChuyen(1,a,b,c);
    auto_taoMangDiChuyen(n-1,b,a,c);
}

void auto_taoSoBuocDiChuyen()
{
	if(soDia==2)
		{
			auto_soBuocDiChuyen = 3;
		}
		if(soDia==3)
		{
			auto_soBuocDiChuyen =7;
		}
		if(soDia>3)
		{
			auto_soBuocDiChuyen = 7;
			for(int i=4;i<=soDia;i++)
			{
				auto_soBuocDiChuyen = auto_soBuocDiChuyen*2;
				auto_soBuocDiChuyen+=1;
			}
		}
}

void auto_xuatMangDiChuyen()
{
	cout<<"Cach di chuyen: "<<endl;
	for(int i=1;i<=auto_soBuocDiChuyen;i++)
	{
		cout<<auto_cotBanDau[i].chiSo<<" "<<auto_cotChuyenDen[i].chiSo<<endl;
	}
}


void auto_diChuyenBlock(KHOICOT cotBanDau, KHOICOT cotChuyenDen)
{
	for(int i=1;i<=soDia;i++)
	{
		if(trangThaiStack[i][cotBanDau.chiSo]!=0)
		{
			block[trangThaiStack[i][cotBanDau.chiSo]].viTriCot = cotChuyenDen.chiSo;
			block[trangThaiStack[i][cotBanDau.chiSo]].toaDoBlock.x = cotChuyenDen.toaDoCot.x;
			for(int s=soDia;s>0;s--)
			{
				if(trangThaiStack[s][cotChuyenDen.chiSo]==0 && trangThaiStack[s+1][cotChuyenDen.chiSo]>block[trangThaiStack[i][cotBanDau.chiSo]].kichThuoc)
				{
					block[trangThaiStack[i][cotBanDau.chiSo]].viTriStack = s;
					block[trangThaiStack[i][cotBanDau.chiSo]].toaDoBlock.y =  cotChuyenDen.stack[s].toaDoStack.y;
					if(block[trangThaiStack[i][cotBanDau.chiSo]].viTriCot == 3 && block[trangThaiStack[i][cotBanDau.chiSo]].viTriStack == block[trangThaiStack[i][cotBanDau.chiSo]].kichThuoc)
					{
						block[trangThaiStack[i][cotBanDau.chiSo]].mauSac = 10;
					}
					break;
				}
			}
			break;
		}
	}
}

void HaNoi()
{
	cout<<"      ||    ||   ||||     ||    || |||||||| ||"<<endl;
	cout<<"      ||    || ||    ||   ||||  || ||    || ||"<<endl;
	cout<<"      |||||||| ||||||||   || || || ||    || ||"<<endl;
	cout<<"      ||    || ||    ||   ||  |||| ||    || ||"<<endl;
	cout<<"      ||    || ||    ||   ||   ||| |||||||| ||"<<endl;
}



//      ||    ||   ||||     ||    || |||||||| ||     //
//      ||    || ||    ||   ||||  || ||    || ||     //
//      |||||||| ||||||||   || || || ||    || ||     //
//      ||    || ||    ||   ||  |||| ||    || ||     //
//      ||    || ||    ||   ||   ||| |||||||| ||     //







