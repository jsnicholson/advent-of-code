#pragma once
#include "Day.h"

#include <string>
#include <map>

class TreeNode {
public:
	const std::string m_name;

private:
	int m_size;
	TreeNode* m_parent=nullptr;
	//std::vector<TreeNode> m_children;
	std::map<std::string, TreeNode> m_children;

public:
	TreeNode(int size, std::string name) : m_size(size), m_name(name) {};

	void AddChild(TreeNode node) {
		node.SetParent(this);
		m_children.insert({ node.m_name, node });
		BubbleUpSize(&node, node.GetSize());
	}
	const int GetSize() { return m_size; }
	TreeNode* GetParent() { return m_parent; }
	TreeNode* GetChild(std::string name) { return &m_children.at(name); };
	std::vector<TreeNode*> GetAllDirectories();

private:
	void SetParent(TreeNode* parent) { m_parent = parent; }
	void BubbleUpSize(TreeNode*, int);
};

class Day7 : public Day {
public:
	typedef std::string command;
	typedef std::vector<std::string> output;
	typedef std::pair<command, output> commandWithOutput;
	std::vector<commandWithOutput> m_commands;

	TreeNode* m_root;

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

	void ProcessCdCommand(TreeNode*&, std::string location);
	void ProcessLsCommand(TreeNode&, output);
};