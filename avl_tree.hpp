
//Starting off with a more C style like implementation
namespace mtl {
	struct Node;

	struct Node {
		Node* parent = nullptr;
		Node* son = nullptr;
		Node* daughter = nullptr;
		
		char balance = 0;

		int value;
		//Consider requiring explicit initialization for non child variables
		//Node(Node* par, char bal) : parent{par}, balance{bal} {};

		~Node();
		Node*& parents_ptr();
	};

	class avl_tree {
	//Temporarily expose internals to public for debugging purposes
	public:
		Node* root = nullptr;
		Node* updateBal(Node* node);
		void rotRight(Node* node);
		void rotLeft(Node* node);

		void rotLR(Node* node);
		void rotRL(Node* node);

		void rebalance(Node* node);

	//public:
		Node* insert(int val);
		void remove(Node* node);

		
		~avl_tree() {
			//Recursively deletes the rest of the nodes, too
			if (root != nullptr)
				delete root;
		}
	};

}