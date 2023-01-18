const int MXR = 32622;
vector <long long > primes;
bool isPrime[MXR + 1];
 
void pre() {
	for(int i = 2 ; i <= MXR ; i++) isPrime[i] = true;
	
	for (int i = 2 ; i <= MXR ; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
			for (long long int j = i * i ; j <= MXR ; j += i) isPrime[j] = false;
		}
	}
}

vector <long long int> factorise(long long int x) {
	vector <long long int> primeFactors;
	
	for (auto p: primes) {
		if (x < p) break;
		if (x % p) continue;
		
		primeFactors.push_back(p);
		
		while ((x % p) == 0) {
			x /= p;
		}
	}
	
	if (x > 1) primeFactors.push_back(x);
	
	return primeFactors;
}
