
int idx, wlen;
char cw[101];

void start(char str[])
{
    idx = 0;
    wlen = 0;

    while (str[idx] == ' ') // selama bertemu spasi atau koma, idx akan bertambah
    {
        idx++;
    }

    while ((str[idx] != ',') && (eop(str) == 0))
    {
        cw[wlen] = str[idx];
        idx++;
        wlen++;
    }

    cw[wlen] = '\0';
}

void reset()
{
    wlen = 0;
    cw[wlen] = '\0';
}

int eop(char str[])
{
    if (str[idx] == ';')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void inc(char str[])
{
    wlen = 0;

    while (str[idx] == ' ') // selama bertemu spasi atau koma, idx akan bertambah
    {
        idx++;
    }

    while ((str[idx] != ',') && (str[idx] != ';'))
    {
        cw[wlen] = str[idx];
        idx++;
        wlen++;
    }

    cw[wlen] = '\0';
}

int getlen()
{
    return wlen;
}

char *getcw()
{
    return cw;
}