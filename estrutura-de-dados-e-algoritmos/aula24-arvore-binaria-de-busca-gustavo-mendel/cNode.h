#pragma once

class cNode	{ 	

private:
	int 	data;
    cNode* 	left;
    cNode* 	right;

public:

	cNode();
	cNode(int d);
	cNode(const cNode& n);

	void 	setLeftChild(cNode* node);
	cNode* 	getLeftChild();
	cNode**	getRefLeftChild();

	void 	setRightChild(cNode* node);
	cNode* 	getRightChild();
	cNode**	getRefRightChild();

	void 	setData(int d);
	int  	getData();

	friend std::ostream &operator<<( std::ostream &output, const cNode &n);


};