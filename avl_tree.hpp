
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
	};

	class avl_tree {
	//Temporarily expose internals to public for debugging purposes
	public:
		Node* root = new Node;

	//Node* updateBal(Node* node);
	//public:
		Node* insert(int val);
		
		~avl_tree() {
			//Recursively deletes the rest of the nodes, too
			delete root;
		}
	};

}