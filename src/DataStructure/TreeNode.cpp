#include "../../include/DataStructure/TreeNode.hpp"

namespace Cpp2020::DataStructure
{ 
    TreeNode::TreeNode(char _character, int32_t _frequency)
    : data_(std::make_shared<NodeData>(_character, _frequency)),
      leaf_(true)
    {}

    TreeNode::TreeNode(TreeNode _leftNode, TreeNode _rightNode)
    {
        leftNode_ = std::make_shared<TreeNode>(_leftNode);
        rightNode_ = std::make_shared<TreeNode>(_rightNode);
        data_ = std::make_shared<NodeData>(leftNode_->data()->frequency() + 
                                           rightNode_->data()->frequency());
    } 

    std::shared_ptr<TreeNode>
    TreeNode::leftNode() const
    {
        return leftNode_; 
    }

    std::shared_ptr<TreeNode>
    TreeNode::rightNode() const
    {
        return rightNode_;
    }  
 
    std::shared_ptr<NodeData>
    TreeNode::data(void) const
    {
        return data_;
    } 

    bool 
    TreeNode::leaf(void) const
    {
        return leaf_;
    }

    const std::shared_ptr<TreeNode>
    TreeNode::walkTree(int8_t rl) const
    {
        return rl == 0 ? leftNode_ : rightNode_;
    }
}    