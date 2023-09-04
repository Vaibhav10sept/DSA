vector<int> stringMatch(string &str, string &pat) {

    // Write your code here

    vector<int>ans;

    int strS = str.length();

    int patS = pat.length();

    int modu = INT_MAX;

    int x = 1;

    int n = 128;

    int s = 0, p = 0;

    int key;

    for (int i = 0; i < patS - 1; i++)

        x = (x * n) % modu;

    for (int i = 0; i < patS; i++)

    {

        s = (n * s + str[i]) % modu;

        p = (n * p + pat[i]) % modu;

    }

    for (int i = 0; i <= strS - patS; i++)

    {

        key = 0;

        if (s == p)

        {

            for (int j = 0; j < patS; j++)

            {

                if (str[i + j] != pat[j])

                {

                    key = 0;

                    break;

                }

                key = 1;

            }

            if (key == 1)

                ans.push_back(i);

        }

        if (i < strS - patS)

        {

            s = ((s - str[i] * x) * n + str[i + patS]) % modu;

            // if(s<0)

            // s=(s+modu);

        }

    }

    return ans;

}

