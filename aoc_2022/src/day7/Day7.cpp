#include "Day7.h"

#include "Utils.hpp"

void Day7::Parse() {
    commandWithOutput commandWithOutput{};
    for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        std::string line = *it;
        // line is a command
        if (line.find('$') != std::string::npos) {
            if (!commandWithOutput.first.empty()) {
                m_commands.push_back(commandWithOutput);
                commandWithOutput = {};
            }
            command command = line.substr(2);
            commandWithOutput.first = command;
            continue;
        }

        commandWithOutput.second.push_back(line);
    }
    m_commands.push_back(commandWithOutput);
}

std::string Day7::Part1() {
    m_root = new TreeNode(0, std::string("/"));
    TreeNode* treePtr = m_root;
    for (std::vector<commandWithOutput>::iterator it = m_commands.begin(); it != m_commands.end(); it++) {
        command command = (*it).first;
        output output = (*it).second;
        auto tokens = Utils::Split(command, ' ');

        if (tokens.front()._Equal("cd")) {
            ProcessCdCommand(treePtr, tokens[1]);
        } else if (tokens.front()._Equal("ls")) {
            ProcessLsCommand(*treePtr, output);
        } else {
            EXIT_FAILURE;
            return std::string("unrecognised command");
        }
    }

    auto directories = m_root->GetAllDirectories();
    directories.erase(std::remove_if(directories.begin(), directories.end(),
        [](auto const& x) {
            return x->GetSize() > 100000;
        }), directories.end());

    int total = std::accumulate(directories.begin(), directories.end(), 0,
        [](int a, auto x) {
            return a + x->GetSize();
        });

    return std::to_string(total);
}

std::string Day7::Part2() {
    return std::string("unimplemented");
}

void Day7::ProcessCdCommand(TreeNode*& treePtr, std::string location) {
    // command to move to root
    if (location._Equal("/")) {
        treePtr = m_root;
        return;
    }
    // command move up by one dir
    if (location._Equal("..")) {
        treePtr = treePtr->GetParent();
        return;
    }
    // move somewhere else
    treePtr = treePtr->GetChild(location);
}

void Day7::ProcessLsCommand(TreeNode& tree, output output) {
    for (output::iterator it = output.begin(); it != output.end(); it++) {
        auto tokens = Utils::Split(*it, ' ');
        if (tokens[0]._Equal("dir")) {
            tree.AddChild(TreeNode(0, tokens[1]));
        } else {
            tree.AddChild(TreeNode(std::stoi(tokens[0]), tokens[1]));
        }
    }
}

void TreeNode::BubbleUpSize(TreeNode* nodePtr, int size) {
    nodePtr = nodePtr->GetParent();
    while (nodePtr != nullptr) {
        nodePtr->m_size += size;
        nodePtr = nodePtr->GetParent();
    }
}

std::vector<TreeNode*> TreeNode::GetAllDirectories() {
    std::vector<TreeNode*> directories{};
    for (auto & x : m_children) {
        if (!x.second.m_children.empty()) {
            directories.push_back(&x.second);
            auto subDirectories = x.second.GetAllDirectories();
            directories.insert(directories.end(), subDirectories.begin(), subDirectories.end());
        }
    }
    return directories;
}