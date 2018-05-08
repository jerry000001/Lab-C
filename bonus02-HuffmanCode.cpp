#include<iostream>  
#include<string> 
#include<vector>
using namespace std; 
struct hTNode //HuffmanTree節點
{
public:
	string element; //元素 
	int quantity; //數量  
	int parent; //父節點  
	int leftChild; //左子節點
	int rightChild; //右子節點
};
struct hCNode //HuffmanCode節點  
{
public:
	string code; //Huffman編碼  
	string hCInfo; //數據  
};
struct HuffmanClass
{
public:
	void setSize(int s)
	{
		size = s;
	}
	int getSize()
	{
		return size;
	}
	void readInput(string &strTmp, int &intTmp)//將輸入push到hNode中
	{
		hNodePtr = new hTNode;
		hNodePtr->element = strTmp;
		hNodePtr->quantity = intTmp;
		hNodePtr->parent = NULL;
		hNodePtr->leftChild = NULL;
		hNodePtr->rightChild = NULL;
		hNode.push_back(hNodePtr);
	}
	void createHuffmanTree() 
	{
		for (i = size; i < (2 * size) - 1; i++)
		{
			min[0] = min[1] = max;
			leftNode = rightNode = NULL;
			for (j = 0; j < i; j++)
			{
				if (hNode[j]->parent == NULL) //對根節點進行尋找
				{
					if (hNode[j]->quantity < min[0]) //找最小值
					{
						min[1] = min[0];
						rightNode = leftNode;
						min[0] = hNode[j]->quantity;
						leftNode = j;
					}
					else if (hNode[j]->quantity < min[1])
					{
						min[1] = hNode[j]->quantity;
						rightNode = j;
					}
				}
			}
			hNodePtr = new hTNode;
			hNodePtr->quantity = hNode[leftNode]->quantity + hNode[rightNode]->quantity;
			hNodePtr->parent = NULL;
			hNodePtr->leftChild = leftNode;
			hNodePtr->rightChild = rightNode;
			hNode.push_back(hNodePtr);
			hNode[leftNode]->parent = j; //J成為原最小值的父節點
			hNode[rightNode]->parent = j;
		}
	}
	void createHuffmanCode() //霍夫曼編碼
	{
		for (i = 0; i < size; i++)
		{
			hCodePtr = new hCNode;
			hCodePtr->hCInfo = hNode[i]->element;
			nTmp = i;
			father = hNode[i]->parent;
			while (father != NULL) //從最底層往樹根回推
			{
				if (hNode[father]->leftChild == nTmp)
				{
					hCodePtr->code.assign("1" + hCodePtr->code);
				}
				else
				{
					hCodePtr->code.assign("0" + hCodePtr->code);
				}
				nTmp = father;
				father = hNode[father]->parent;
			}
			hCode.push_back(hCodePtr);
		}
	}
	void displayHuffmanCode() 
	{
		for (i = 0; i < size; i++) cout << hCode[i]->hCInfo << ":" << hCode[i]->code << endl;
	}
private:
	vector<hTNode *> hNode;
	vector<hCNode *> hCode;
	hTNode* hNodePtr;
	hCNode* hCodePtr;
	int size; 
	int leftNode, rightNode; //左右節點
	int i, j; //for迴圈
	int min[2]; //最小的兩個值
	int nTmp; //節點暫存
	int father; //父節點
	const int max = 99999; //最大值
};
void main()
{
	int intTmp;
	string strTmp;
	HuffmanClass* hM = new HuffmanClass;
	hM->setSize(6);
	for (int i = 0; i < hM->getSize(); i++)
	{
		cin >> strTmp >> intTmp;
		hM->readInput(strTmp, intTmp);
	}
	hM->createHuffmanTree();
	hM->createHuffmanCode();
	hM->displayHuffmanCode();
	system("pause");
}