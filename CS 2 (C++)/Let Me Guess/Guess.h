#ifndef GUESS_H
#define GUESS_H
#include <memory>
#include <string>

template<typename T>
struct Guessnode{

	Guessnode(T t){ data = t, left = nullptr, right = nullptr; }
	T data;
	std::shared_ptr<Guessnode<T>> left;
	std::shared_ptr<Guessnode<T>> right;



};
template<typename T>
void zig(std::shared_ptr<Guessnode<T>> & tree){
	if (!tree){
		return;
	}
	if (!tree->right){
		return;
	}
	auto A = tree;
	tree = tree->right;
	A->right = tree->left;
	tree->left = A;

}
template<typename T>
void zag(std::shared_ptr<Guessnode<T>> & tree){
	if (!tree){
		return;
	}
	if (!tree->left){
		return;
	}
	auto A = tree;
	tree = tree->left;
	A->left = tree->right;
	tree->right = A;
}
#endif

