#pragma once

namespace BSL {

template <class T>
class SingleNode {
	public:
		SingleNode<T>();
		SingleNode<T>(const T &data);
		SingleNode<T>(SingleNode<T>* node);
		SingleNode<T>(const T &data, SingleNode<T>* node);
		SingleNode<T>(SingleNode<T>* node, const T &data);
		~SingleNode<T>();

		T data;
		SingleNode<T>* n;
};

template <class T>
SingleNode<T>::SingleNode() {
	this->n = 0;
}

template <class T>
SingleNode<T>::SingleNode(const T &data) {
	this->data = data;
	this->n = 0;
}

template <class T>
SingleNode<T>::SingleNode(SingleNode<T>* node) {
	this->n = node;
}

template <class T>
SingleNode<T>::SingleNode(const T &data, SingleNode<T>* node) {
	this->data = data;
	this->n = node;
}

template <class T>
SingleNode<T>::SingleNode(SingleNode<T>* node, const T &data) {
	this->data = data;
	this->n = node;
}

template <class T>
SingleNode<T>::~SingleNode() {
	this->n = 0;
}

}

