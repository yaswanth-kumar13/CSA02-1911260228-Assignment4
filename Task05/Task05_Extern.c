
int veg_token = 1000;
int nonveg_token = 2000;

int next_veg_token(void)
{
    return ++veg_token;
}

int next_nonveg_token(void)
{
    return ++nonveg_token;
}
