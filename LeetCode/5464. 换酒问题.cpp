int numWaterBottles(int numBottles, int numExchange) {
	int num = numBottles, left = 0;
	bool is_able_to_exchange = true;
	while (is_able_to_exchange)
	{
		numBottles -= numExchange;
		numBottles += 1;
		if (numBottles <= 0)
		{
			is_able_to_exchange = false;
			return num;
		}
		num++;
	}
	return numBottles;
}