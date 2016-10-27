int encode_varint(char *buf, uint64_t x)
{
    int n;
    n = 0;
    while(x>127)
    {
    buf[n++] = (char)(0x80 | (x & 0x7f));
    x >>= 7;
    }
    buf[n++] = (char)x;
    return n;
}

uint64_t decode_varint(char *buf)
{
    int shift, n;
    uint64_t x, c;

    n = 0;
    x = 0;

    for(shift = 0; shift <64; shift += 7)
    {
        c = (uint64_t)buf[n++];
        x |= (c & 0x7f) << shitf;
        if ((c & 0x80 )== 0)
        {
            break;
        }
    }
    return x ;
}    
        
