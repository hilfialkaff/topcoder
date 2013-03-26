string convertInt(int number)
{
    stringstream ss;
    ss << number;
    return ss.str();
}

void print_vector(vector<long long> v)
{
	FOR(i, 0, v.size()) {
		cout << v[i] << " ";
	}
	cout << endl;
}
