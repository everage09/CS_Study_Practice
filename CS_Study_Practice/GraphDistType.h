#pragma once
template <typename T>
struct GraphDistType
{
	bool operator < (const GraphDistType& otherNode) const;
	bool operator == (const GraphDistType& otherNode) const;
	bool operator <= (const GraphDistType& otherNode) const;
	bool operator > (const GraphDistType& otherNode) const;
	bool operator >= (const GraphDistType& otherNode) const;
	T fromVertex;
	T toVertex;
	int distance;
};

template<typename T>
inline bool GraphDistType<T>::operator<(const GraphDistType& otherNode) const
{
	return distance < otherNode.distance;
}

template<typename T>
inline bool GraphDistType<T>::operator==(const GraphDistType& otherNode) const
{
	return distance == otherNode.distance;
}

template<typename T>
inline bool GraphDistType<T>::operator<=(const GraphDistType& otherNode) const
{
	return distance <= otherNode.distance;
}

template<typename T>
inline bool GraphDistType<T>::operator>(const GraphDistType& otherNode) const
{
	return distance > otherNode.distance;
}

template<typename T>
inline bool GraphDistType<T>::operator>=(const GraphDistType& otherNode) const
{
	return distance >= otherNode.distance;
}
