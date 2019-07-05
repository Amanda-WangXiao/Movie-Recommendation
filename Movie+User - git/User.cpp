﻿#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <cctype>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

const int MaxN = 1000;
int nkey, totNode, root;
map <string, bool> vis;
char s[MaxN + 5];
struct TREE {
	int left, right;
	string str;
}tree[MaxN + 5];

void Insert(int nr, string str)
{
	if (str == tree[nr].str) return;
	else if (str < tree[nr].str) {	
		if (tree[nr].left == -1) {	
			tree[nr].left = ++totNode;
			tree[tree[nr].left].str = str;
			return;
		}
		else Insert(tree[nr].left, str);	
	}
	else {	
		if (tree[nr].right == -1) {	
			tree[nr].right = ++totNode;
			tree[tree[nr].right].str = str;
			return;
		}
		else Insert(tree[nr].right, str);
	}
}

void BuildTree1()	
{
	freopen("keys1.txt", "r", stdin);	
	scanf("%d", &nkey); totNode = 0; vis.clear(); 
	for (int i = 0; i <= MaxN; i++) {
		tree[i].left = tree[i].right = -1;
		tree[i].str = "";
	}
	root = -1;
	for (int i = 1; i <= nkey; i++) {
		string str;
		cin >> str;		
		for (int j = 0; j < str.length(); j++)	
			str[j] = tolower(str[j]);
		if (root == -1) {	
			root = 0;
			tree[root].str = str;
		}
		else Insert(root, str);	
	}		
	fclose(stdin);
}

void BuildTree2()
{
	freopen("keys2.txt", "r", stdin);	
	scanf("%d", &nkey); totNode = 0; vis.clear(); 
	for (int i = 0; i <= MaxN; i++) {	
		tree[i].left = tree[i].right = -1;
		tree[i].str = "";
	}
	root = -1;
	for (int i = 1; i <= nkey; i++) {
		string str;
		cin >> str;		
		for (int j = 0; j < str.length(); j++)	
			str[j] = tolower(str[j]);
		if (root == -1) {	
			root = 0;
			tree[root].str = str;
		}
		else Insert(root, str);	
	}		
	fclose(stdin);
}

void BuildTree3()	
{
	freopen("keys3.txt", "r", stdin);	
	scanf("%d", &nkey); totNode = 0; vis.clear(); 
	for (int i = 0; i <= MaxN; i++) {	
		tree[i].left = tree[i].right = -1;
		tree[i].str = "";
	}
	root = -1;
	for (int i = 1; i <= nkey; i++) {
		string str;
		cin >> str;	
		for (int j = 0; j < str.length(); j++)
			str[j] = tolower(str[j]);	
		if (root == -1) {
			root = 0;
			tree[root].str = str;
		}
		else Insert(root, str);	
	}		
	fclose(stdin);
}

void BuildTree4()	
{
	freopen("keys4.txt", "r", stdin);
	scanf("%d", &nkey); totNode = 0; vis.clear(); 
	for (int i = 0; i <= MaxN; i++) {
		tree[i].left = tree[i].right = -1;
		tree[i].str = "";
	}
	root = -1;
	for (int i = 1; i <= nkey; i++) {
		string str;
		cin >> str;		
		for (int j = 0; j < str.length(); j++)	
			str[j] = tolower(str[j]);
		if (root == -1) {	
			root = 0;
			tree[root].str = str;
		}
		else Insert(root, str);	
	}		
	fclose(stdin);
}

void BuildTree5()	
{
	freopen("keys5.txt", "r", stdin);	
	scanf("%d", &nkey); totNode = 0; vis.clear(); 
	for (int i = 0; i <= MaxN; i++) {	
		tree[i].left = tree[i].right = -1;
		tree[i].str = "";
	}
	root = -1;
	for (int i = 1; i <= nkey; i++) {
		string str;
		cin >> str;		
		for (int j = 0; j < str.length(); j++)
			str[j] = tolower(str[j]);
		if (root == -1) {	
			root = 0;
			tree[root].str = str;
		}
		else Insert(root, str);	
	}		
	fclose(stdin);
}




bool Find(int nr, string str)	
{
	if (tree[nr].str == str) return true;	
	else if (str < tree[nr].str) {	
		if (tree[nr].left == -1) return false;
		else return Find(tree[nr].left, str);
	}
	else {
		if (tree[nr].right == -1) return false;
		else return Find(tree[nr].right, str);
	}
}

void Dfs(int root)
{
	if (root == -1) return ;
	Dfs(tree[root].left);
	cout << tree[root].str << endl;
	Dfs(tree[root].right);
}

void Solve()
{
	freopen("Words.txt", "r", stdin);
	int cnt = 0;
	while (~scanf("%s", s)) {
		string str = "";
		for (int i = 0; i < strlen(s); i++) str += s[i];
		for (int i = 0; i < strlen(s); i++) str[i] = tolower(str[i]);
		if (!vis[str] && Find(root, str)) {	
			cnt++;	
		}
	}
	printf("%d\n", cnt);
	fclose(stdin);
}

int main()
{

	freopen("UserValue2.txt", "w", stdout);
	BuildTree2();
	Solve();
	fclose(stdout);
	
	freopen("UserValue3.txt", "w", stdout);
	BuildTree3();
	Solve();
	fclose(stdout);
	
	freopen("UserValue4.txt", "w", stdout);
	BuildTree4();
	Solve();
	fclose(stdout);
	
	freopen("UserValue5.txt", "w", stdout);
	BuildTree5();
	Solve();
	fclose(stdout);
	
	freopen("UserValue1.txt", "w", stdout);
	BuildTree1();
	Solve();
	fclose(stdout);	
	


	int a=0;
	int b=0;
	int c=0;
	int d=0;
	int e=0;
	
    freopen("UserValue1.txt", "r", stdin);
	scanf("%d", &a);
    fclose(stdin);
    	
    freopen("UserValue2.txt", "r", stdin);
	scanf("%d", &b);
    fclose(stdin);	
    	
    freopen("UserValue3.txt", "r", stdin);
	scanf("%d", &c);
    fclose(stdin);	
    	
    freopen("UserValue4.txt", "r", stdin);
	scanf("%d", &d);
    fclose(stdin);	
    	
    freopen("UserValue5.txt", "r", stdin);
	scanf("%d", &e);
    fclose(stdin);	
    	
    int ttt1;
    int ttt2;
    
    if(a>=b&&a>=c&&a>=d&&a>=e){
    	ttt1=1;
    	if(b>=c&&b>=d&&b>=e) ttt2=2;
    	else if(c>=b&&c>=d&&c>=e) ttt2=3;
    	else if(d>=b&&d>=c&&d>=e) ttt2=4;
    	else ttt2=5;
	}
	
	else if(b>=a&&b>=c&&b>=d&&b>=e){
    	ttt1=2;
    	if(a>=c&&a>=d&&a>=e) ttt2=1;
    	else if(c>=a&&c>=d&&c>=e) ttt2=3;
    	else if(d>=a&&d>=c&&d>=e) ttt2=4;
    	else ttt2=5;
	}
	
	else if(c>=a&&c>=b&&c>=d&&c>=e){
    	ttt1=3;
    	if(a>=b&&a>=d&&a>=e) ttt2=1;
    	else if(b>=a&&b>=d&&b>=e) ttt2=2;
    	else if(d>=a&&d>=b&&d>=e) ttt2=4;
    	else ttt2=5;
	}
	
	
	else if(d>=a&&d>=b&&d>=c&&d>=e){
    	ttt1=4;
    	if(a>=b&&a>=c&&a>=e) ttt2=1;
    	else if(b>=a&&b>=c&&b>=e) ttt2=2;
    	else if(c>=a&&c>=b&&c>=e) ttt2=3;
    	else ttt2=5;
	}
	
	else{
		ttt1=5;
		if(a>=b&&a>=c&&a>=d) ttt2=1;
    	else if(b>=a&&b>=c&&b>=e) ttt2=2;
    	else if(c>=a&&c>=b&&c>=e) ttt2=3;
    	else ttt2=4;
	}
	
		
	freopen("UserOverTag.txt", "w", stdout); 
	printf("%d\n%d\n", ttt1,ttt2);
	fclose(stdout);
	
	
	
	
	
	
	
	if(ttt1==1){
		if(ttt2==2){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ���ƻúͶ���	Ϊ���Ƽ���������3����Һ�������ӳ�3");
			fclose(stdout);
		}
		else if(ttt2==3){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ���ƻú͸�Ц	Ϊ���Ƽ������̡�������3���ٱ��Ǿ�");
			fclose(stdout);	
		}
		else if(ttt2==4){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ���ƻúͿֲ�	Ϊ���Ƽ������Ǵ��桢���Σ���Լ����������");
			fclose(stdout);
		}
		else if(ttt2==5){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ���ƻúͰ���	Ϊ���Ƽ�������Ѱ�����Ǽ��ع���ǧ��֮�ǡ��������ܶ�Ա");
			fclose(stdout);
		}
	} 
	
	else if(ttt1==2){
		if(ttt2==1){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ�������Ϳƻ�	Ϊ���Ƽ���������ͷ����ҡ�xս��");
			fclose(stdout);
		}
		else if(ttt2==3){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ�������͸�Ц	Ϊ���Ƽ������С������ȭ���ڼ��ع�");
			fclose(stdout);
		}
		else if(ttt2==4){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ�������Ϳֲ�	Ϊ���Ƽ�����˹��2���ڰ���˵5��ľ����3");
			fclose(stdout);	
		}
		else if(ttt2==5){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ�������Ͱ���	Ϊ���Ƽ���ʷ��˹�򸾡���ѧ������׳־����");
			fclose(stdout);
		}
	}
	
	else if(ttt1==3){
		if(ttt2==1){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ����Ц�Ϳƻ�	Ϊ���Ƽ������������ˣ������ߺš��ص�δ��");
			fclose(stdout);
		}
		else if(ttt2==2){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ����Ц�Ͷ���	Ϊ���Ƽ����ɳ����������˽�̽���������ع�2");
			fclose(stdout);
		}
		else if(ttt2==4){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ����Ц�Ϳֲ�	Ϊ���Ƽ����˼�ʧ���¿��Ĺ����Ĺ�����");
			fclose(stdout);
		}
		else if(ttt2==5){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ����Ц�Ͱ���	Ϊ���Ƽ����������׸��������Ρ�ϲ��֮��");
			fclose(stdout);
		}
	}
	
	else if(ttt1==4){
		if(ttt2==1){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ���ֲ��Ϳƻ�	Ϊ���Ƽ�������2�������ޡ�����");
			fclose(stdout);
		}
		else if(ttt2==2){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ���ֲ��Ͷ���	Ϊ���Ƽ�������սʿ�������������������");
			fclose(stdout);
		}
		else if(ttt2==3){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ���ֲ��͸�Ц	Ϊ���Ƽ����ػ�ҹ��һü���ˡ���ʬ����");
			fclose(stdout);
		}
		else if(ttt2==5){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ���ֲ��Ͱ���	Ϊ���Ƽ����ҵ�ɥʬŮ�ѡ��˹���δ�ˡ�ٻŮ�Ļ�3");
			fclose(stdout);
		}
	}

	else if(ttt1==5){
		if(ttt2==1){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ������Ϳƻ�	Ϊ���Ƽ���������֡�������֮�¹ⱦ�С�������");
			fclose(stdout);
		}
		else if(ttt2==2){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ������Ͷ���	Ϊ���Ƽ������ߴ�����ɽ���ˡ��ഺ��Ѫ");
			fclose(stdout);
		}
		else if(ttt2==3){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ������͸�Ц	Ϊ���Ƽ����Ʋ��������㡢��Щ�꣬����һ��׷����Ů����");
			fclose(stdout);
		}
		else if(ttt2==4){
			string ttt3 ;
			freopen("������UserOverTag������.txt", "w", stdout); 
			printf("������ʵĵ�Ӱ����Ϊ������Ϳֲ�	Ϊ���Ƽ���ٻŮ�Ļꡢ��Ϊ����ȥƤ�����˹�����");
			fclose(stdout);
		}
	}
	 
	 
	
	
	return 0;
}
