// KingOfXishu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <aclapi.h>
#include <queue>
#include <vector>
#include "Node.h"
#include "ParentA.h"
#include "ParentB.h"
#include "TreeNode.h"
#include "globalv.h"
#include "ModuleA.h"
#include "ModuleB.h"
//#include "ModuleB.h"
#include"time.h"
using namespace std;
int g_int = 0;
vector<int> makeVector(size_t n) {
  vector<int> out;
  for (size_t i = 0; i < n; i++) {
    out.push_back(i);
  }
  return out;
}

/**
 * 构建二叉树
 */
TreeNode<int>* makeTree(vector<int> input, size_t rootIndex);
TreeNode<int>* makeTree(vector<int> input, size_t rootIndex) {
  if (rootIndex >= input.size()) {
    return nullptr;
  }
  int current = input[rootIndex];
  // TreeNode root,用这种方式创建的对象出了栈就直接被销毁，它分配内存在栈空间

  TreeNode<int>* root = new TreeNode<int>(current);
  root->left = makeTree(input, rootIndex * 2 + 1);
  root->right = makeTree(input, rootIndex * 2 + 2);
  return root;
}

void printTreeNode(TreeNode<int>* root) {
  if (root == nullptr) {
    return;
  }
  cout << root->value;
  printTreeNode(root->left);
  printTreeNode(root->right);
}

/**
 * 层序遍历二叉树
 */
void visitTreeNode(TreeNode<int>* root) {
  queue<TreeNode<int>*> q;
  q.push(root);
  while (q.size() > 0) {
    TreeNode<int>* top = q.front();
    cout << top->value;
    q.pop();
    if (top->left) {
      q.push(top->left);
    }
    if (top->right) {
      q.push(top->right);
    }
  }
  cout << "\n";
}

/**
 * 公共父节点
 */
TreeNode<int>* publicFather(TreeNode<int>* root,
                            TreeNode<int>* p,
                            TreeNode<int>* q) {
  if (!root || root == p || root == q) {
    return root;
  }
  TreeNode<int>* left = publicFather(root->left, p, q);
  TreeNode<int>* right = publicFather(root->right, p, q);
  if (left && right) {
    return root;
  }
  return left ? left : right;
}

/**
 * 函数指针
 */
void funcPointCallBack();
void funcPointCallBack() {
  pa::ParentA v_pa(1);
  // 所以使用类的成员函数作为回调函数的解决方法有两种：不使用成员函数(使用友元操作符friend的C函数访问类的数据成员)；使用静态成员函数
  int res = v_pa.add_2(4, 2, pa::ParentA::add_1);
}

/*最小公共父节点*/
void callPublicFather() {
  TreeNode<int>* root = makeTree(makeVector(10), 0);
  TreeNode<int>* p = root;
  TreeNode<int>* q = root;

  while (p) {
    if (p->value == 3) {
      break;
    }
    p = p->left;
  }

  while (q) {
    if (q->value == 6) {
      break;
    }
    q = q->right;
  }
  cout << publicFather(root, p, q)->value;
}

Node<int>* makeLinkedList(int size) {
  Node<int>* head = nullptr;
  Node<int>* p = nullptr;
  for (int i = 0; i < size; i++) {
    Node<int>* cur = new Node<int>(i);
    if (head == nullptr) {
      head = cur;
      p = cur;
    } else {
      p->next = cur;
      p = p->next;
    }
  }
  return head;
}

void printLinkedList(Node<int>* head) {
  while (head) {
    cout << head->getValue();
    head = head->next;
  }
  cout << "\n";
}

/*倒置 m-n*/
/*1->2->3->4->5*/
Node<int>* reverseLinkedListbyK(Node<int>* head, int m, int n) {
  Node<int>* dummy = new Node<int>(-1);
  dummy->next = head;
  Node<int>* pre = dummy;
  Node<int>* cur = nullptr;
  for (size_t i = 0; i < m - 1; i++) {
    pre = pre->next;
  }
  cur = pre->next;
  for (size_t i = 0; i < n - m; i++) {
    Node<int>* tmp = cur->next;
    cur->next = tmp->next;
    tmp->next = pre->next;
    pre->next = tmp;
  }
  return dummy->next;
}

Node<int>* insterSortList(Node<int>* head) {
  Node<int>* dummy = new Node<int>(-1);
  Node<int>* cur = dummy;
  while (head) {
    // head 指向的将要被排序的节点
    Node<int>* tmp = head->next;
    cur = dummy;
    //遍历排好序的列表
    while (cur->next && cur->next->getValue() <= head->getValue()) {
      cur = cur->next;
    }
    // cur
    // 指向的是排好序的节点中最后一个小于等于插入节点（head）的节点，将head插入在它(cur)后面即可
    head->next = cur->next;
    cur->next = head;
    head = tmp;
  }
  return dummy->next;
}

Node<int>* mergeSort(Node<int>* head1, Node<int>* head2) {
  return 0;
}

int debugSogouLevel() {
 STARTUPINFO si = {sizeof(STARTUPINFO)};
  PROCESS_INFORMATION pi = {0};
  //char lpWStr[] =
  //    "\"C:\\Project\\sogouexplorer\\_appdata\\Bin\\QBSetupNew.exe\" \"C:\\Project\\sogouexplorer\\bin\Debug\" \"-type2\"";

  char lpWStr[] =
      "\"C:\\Project\\sogouexplorer\\_appdata\\Bin\\QBSetupNew.exe\" -GetImage2_200 27046";

    //char lpWStr[] =
    //  "\"C:\\Project\\sogouexplorer\\_appdata\\Bin\\QBSetupNew.exe\" -extract \"C:\\Project\\sogouexplorer\\bin\Debug\"";
  
  //char lpWStr[] =
  //    "\"C:\\Project\\sogouexplorer\\_appdata\\Bin\\sogou_explorer_11.0.1.35428_0000.exe\"";
  HANDLE hMapping = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0,
                          (200 * 1024) + 4, "SE_CHANGELOG_IMAGE_27046");
  if (!hMapping) {
    return 0;
  }
  if (::CreateProcess(NULL, lpWStr, NULL, NULL, FALSE, 0, NULL, NULL,
                      &si, &pi)) {
    ::WaitForSingleObject(pi.hProcess, INFINITE);
    char* lpszData =
        (char*)::MapViewOfFile(hMapping, FILE_MAP_ALL_ACCESS, 0, 0, 0);
    if (lpszData) {
      DWORD dwSize = *(DWORD*)lpszData;  // 4字节存长度
      char* pRealData = lpszData + 4; //数据的起始值
      cout << dwSize;
      char szBuffer[65536];
      sprintf(szBuffer, "%s", pRealData);
      cout << szBuffer;
    }


    ::CloseHandle(pi.hProcess);
    ::CloseHandle(pi.hThread);
  }
  DWORD error_code = GetLastError();
  std::cout<<"";
  return 0;
}

/*
* 研究下强制拷贝
*/
int FileCopyTest() {


    return 0;
}

bool isMatch2(std::wstring s, std::wstring p) {
  int n = s.size(), m = p.size();
  int i = 0, j = 0, iStart = -1, jStart = -1;
  while (i < n) {
    if (j < m && (s[i] == p[j] || p[j] == '?')) {
      i++;
      j++;
    } else if (j < m && p[j] == '*') {
      iStart = i;
      jStart = j++;
    } else if (iStart >= 0) {
      i = ++iStart;
      j = jStart + 1;
    } else
      return false;
  }
  while (j < m && p[j] == '*')
    j++;
  return j == m;
}

bool isMatch(std::wstring s, std::wstring p) {
  int m = s.size();
  int n = p.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1));
  dp[0][0] = true;
  for (int i = 1; i <= n; ++i) {
    if (p[i - 1] == '*') {
      dp[0][i] = true;
    } else {
      break;
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (p[j - 1] == '*') {
        dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
      } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      }
    }
  }
  return dp[m][n];
}

void TestIsMatchs() {
  clock_t start, finish;
  start = clock();
  for (int i = 0; i < 5000; i++) {
    if (isMatch(L"C:"
                L"\\Users\\yogachen\\AppData\\Roaming\\SogouExplorer\\368859fc2"
                L"628f9a13427c69ff0bbddce\\DailyBackup\\adbdata.dat.2022-12-08",
                L"C:\\Users\\yogachen\\AppData\\Roaming\\SogouExplorer\\*"
                L"\\DailyBackup\\*")) {
      // cout << "success";
    }
  }
  finish = clock();
  printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
}

void TestGlobalVar() {
    //多文件共享变量 
    //1、 external 声明
    //2、 定义且只能定义一次（在任意一个源文件定义即可）
    //3、 多处修改
  pb::ParentB* pb = new pb::ParentB();
  pb->parentB();
  cout << g_int << " " << &g_int;
  RunModuleA();
  //RunModuleB();
}

void TestStaticVar() {
  // 静态变量不同文件之间是不共享的
  AddSa();
  cout << getGlobal(); //通过方法暴露出去就可以
  cout << "\n";
  PrintSa();
}
int main() {
  funcPointCallBack();
  makeTree(makeVector(10), 0);
  printTreeNode(makeTree(makeVector(10), 0));
  cout << ">>>>>>>\n";
  visitTreeNode(makeTree(makeVector(10), 0));
  callPublicFather();
  cout << "\n";
  Node<int>* head = makeLinkedList(5);
  printLinkedList(reverseLinkedListbyK(head, 2, 5));
  printLinkedList(insterSortList(head));
  debugSogouLevel();

  //TestGlobalVar();
  TestStaticVar();
}
