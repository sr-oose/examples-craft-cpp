#ifndef NODES_H_
#define NODES_H_

#include <memory>
#include <vector>
#include <iostream>
#include <sstream>

class TreeNode;
using TreeNodePtr = std::shared_ptr<TreeNode>;

class TreeNode {
public:
	virtual std::string getExpressionString() = 0;

	virtual float eval() = 0;

	virtual void addChild(TreeNodePtr child) = 0;

	virtual ~TreeNode() = default;

	virtual int precedence() = 0;

};

class CompositeNode : public TreeNode {
public:

	virtual void addChild(TreeNodePtr child) override {
		children.push_back(child);
	}

protected:
	std::vector<TreeNodePtr> children;
};

class BinaryOp : public CompositeNode {
public:
	BinaryOp(TreeNodePtr lhs, TreeNodePtr rhs){
		CompositeNode::addChild(lhs);
		CompositeNode::addChild(rhs);
	}

	virtual TreeNodePtr getLHS(){
		return children[0];
	}

	virtual TreeNodePtr getRHS(){
		return children[1];
	}

	virtual void addChild(TreeNodePtr child) override {
		//Do not allow adding further children
	}

	virtual std::string getOpString() = 0;

	virtual std::string getExpressionString() override {
		std::stringstream strstr{};
		if (getLHS()->precedence() < precedence())
			strstr << "(" << getLHS()->getExpressionString() << ")";
		else
			strstr << getLHS()->getExpressionString();
		strstr << " " << getOpString() << " ";
		if (getRHS()->precedence() < precedence())
			strstr << "(" << getRHS()->getExpressionString() << ")";
		else
			strstr << getRHS()->getExpressionString();
		return strstr.str();
	}

};

class UnaryOp : public CompositeNode {
public:
	UnaryOp(TreeNodePtr arg){
		CompositeNode::addChild(arg);
	}

	virtual void addChild(TreeNodePtr child) override {
		//Do not allow adding further children
	}

	virtual TreeNodePtr getArg(){
		return children[0];
	}

	virtual std::string getOpString() = 0;

	virtual std::string getExpressionString() override {
		if (getArg()->precedence() < precedence())
			return getOpString() + "(" + getArg()->getExpressionString() + ")";
		else
			return getOpString() + getArg()->getExpressionString();
	}
};

class Multiply : public BinaryOp {
public:
	Multiply(TreeNodePtr lhs, TreeNodePtr rhs) : BinaryOp{lhs, rhs}{ }

	virtual float eval() override {
		return getLHS()->eval() * getRHS()->eval();
	}

	virtual std::string getOpString() override {
		return "*";
	}

	virtual int precedence() override {
		return 2;
	}
};

class Add : public BinaryOp {
public:
	Add(TreeNodePtr lhs, TreeNodePtr rhs) : BinaryOp{lhs, rhs}{ }

	virtual float eval() override {
		return getLHS()->eval() + getRHS()->eval();
	}

	virtual std::string getOpString() override {
		return "+";
	}

	virtual int precedence() override {
		return 1;
	}
};

class Negate : public UnaryOp {
public:
	Negate(TreeNodePtr arg) : UnaryOp{arg}{ }

	virtual float eval() override {
		return -getArg()->eval();
	}

	virtual std::string getOpString() override {
		return "-";
	}

	virtual int precedence() override {
		return 3;
	}
};

class Leaf : public TreeNode {
public:
	virtual void addChild(TreeNodePtr child) override {}

	virtual int precedence() override {
		return 10;
	}
};


class Number : public Leaf {
public:
	Number(float value) : value(value) { }

	virtual float eval() override {
		return value;
	}

	virtual std::string getExpressionString() override {
		std::stringstream strstr{};
		strstr << value;
		return strstr.str();
	}

private:
	float value;
};


#endif
