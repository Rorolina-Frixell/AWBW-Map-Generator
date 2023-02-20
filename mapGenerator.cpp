#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}
int main()
{
    srand((int)time(0));
    int r, l, x = 0, y = 1, f = 3, x1 = 0, y1 = 0;                                               // r = random; f = base limit; x1 , y1 = base(x, y);
    int a1 = 0, b1 = 0, a2 = 0, b2 = 0, a3 = 0, b3 = 0, z, mx, my, ma1, ma2, ma3, mb1, mb2, mb3; // mx, my, z, ma, mb = distance; l = line break; a, b = base(x, y);
    int mcx1, mcx2, mcx3, mcy2, mcy3, mcy1, mcx4, mcy4, mcx5, mcy5;                              // mcx , mcy = cities distance;
    int
        cy1,
        cy2, cy3, cy4, cy5, cy6, cy7, cy8, cy9, cy10, cy11, cy12, cy13, cy14, cy15, cy16, cx1, cx2, cx3,
        cx4, cx5, cx6, cx7, cx8, cx9, cx10, cx11, cx12, cx13, cx14, cx15, cx16; // cities (x,y);
    for (int i = 1; i < 201; ++i)                                               // first loop for base
    {
        x = x + 1;
        mx = abs(x - x1); // abs for distance calculate
        my = y - y1;
        z = mx + my; // distance from base to base
        r = 0;       // i dont think this is necessary
        if (x > 1)
        {
            if (y > 1)
            { // x=1, y=1 is sea
                if (x < 6)
                { // cant let the base too far ahead
                    if (z == 6)
                    { // distance between bases
                        if (f > 1)
                        {
                            r = random(3, 5);
                        }
                    }
                }
            }
        } // random base placement with limit of 3 bases(f = 3)
        if (r >= 4)
        {              // this is base
            f = f - 1; // limit reduce
            x1 = x;    // distance calculate
            y1 = y;
            a2 = x; // this is base 2 (x,y)
            b2 = y;
            if (f == 2)
            { // this is base 1 (x,y)
                a1 = x;
                b1 = y;
            }
        }
        if (x > 1)
        {
            if (x < 8)
            { // this is base 3 (x,y)
                if (y < 20)
                { // y=20 is also sea
                    if (z > 12)
                    { // base 3 need z (space) = 14 aka lone base
                        if (f == 1)
                        {
                            f = f - 1;
                            r = random(3, 6);
                            if (r >= 4)
                            {
                                a3 = x;
                                b3 = y;
                            }
                        }
                    }
                }
            }
        }
        // This is plan B if stuff not working
        if (a1 == 0)
        {
            a1 = random(2, 4);
            b1 = random(2, 3);
        }
        if (a2 == 0)
        {
            a2 = random(2, 6);
            b2 = random(4, 6);
        }
        if (y > 16)
        {
            if (a3 == 0)
            {
                a3 = random(3, 5);
                b3 = random(17, 19);
            }
        }
        l = i % 10; // for downspace
        if (l == 0) // downspace and y
        {
            y = y + 1;
            x = 0;
        }
    }
    printf(" This is base (x,y)\n %d.%d; %d.%d; %d.%d\n", a1,
           b1, a2, b2, a3, b3); // base x,y
    printf("\n Loop for cities placement\n");
    l = 0;
    y = 1;
    x1 = 0;
    y1 = 0;
    mx = 0;
    my = 0;
    f = 16;
    x = 0;
    for (int i = 1; i < 201; ++i) // city placement
    {
        x = x + 1;
        r = 0; // still... should delete this tho
        ma1 = abs(x - a1);
        ma2 = abs(x - a2);
        ma3 = abs(x - a3); // base distance
        mb1 = abs(y - b1);
        mb2 = abs(y - b2);
        mb3 = abs(y - b3); // base distance
        mcx1 = abs(x - cx1);
        mcx2 = abs(x - cx2);
        mcx4 = abs(x - cx8);
        mcx3 = abs(x -
                   cx4);
        mcx5 = abs(x - cx11); // cities distance
        mcy1 = abs(y - cy1);
        mcy2 = abs(y - cy2);
        mcy4 = abs(x - cy8);
        mcy3 = abs(y -
                   cy4);
        mcy5 = abs(y - cy11);
        if (x > 1)
        {
            if (y > 1)
            { // sea
                if (x != a2)
                { // to not overwrite base 2
                    if (f > 13)
                    { // base 1 cities (3) with limit of 16
                        if (ma1 + mb1 >= 3)
                        {
                            if (ma1 + mb1 < 5)
                            { // distance from base 1
                                if (f == 16)
                                {
                                    printf("%d.%d; ", x, y);
                                    f = f - 1;
                                    cx1 = x;
                                    cy1 = y;
                                }
                                // city 1 (x,y)
                                else if (f == 15)
                                {
                                    if (mcx1 + mcy1 >= 3)
                                    { // distance from cities to cities
                                        printf("%d.%d; ", x, y);
                                        f = f -
                                            1;
                                        cx2 = x;
                                        cy2 = y;
                                    }
                                } // city 2 (x,y)
                                else if (f == 14)
                                {
                                    if (mcx1 + mcy1 >= 3)
                                    {
                                        if (mcx2 + mcy2 >= 3)
                                        {
                                            printf("%d.%d;", x, y);
                                            f = f - 1;
                                            cx3 = x;
                                            cy3 = y;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } // city 3 xy
        if (x > 1)
        {
            if (f <= 13)
            {
                if (f >= 10)
                { // base 2 cities (4)
                    if (ma2 + mb2 == 3)
                    {
                        if (f == 13)
                        {
                            if (x != cx3)
                            {
                                printf("%d.%d; ", x, y);
                                f = f -
                                    1;
                                cx4 = x;
                                cy4 = y;
                            }
                        } // city 4 xy
                        else if (f == 12)
                        {
                            if (mcx3 + mcy3 >= 3)
                            {
                                printf("%d.%d; ", x, y);
                                f = f -
                                    1;
                                cx5 = x;
                                cy5 = y;
                            }
                        } // city 5 xy
                        else if (f == 11)
                        {
                            mcx1 = abs(x - cx5);
                            mcy1 = abs(y -
                                       cy5);
                            if (mcx1 + mcy1 >= 2)
                            {
                                printf("%d.%d; ", x, y);
                                cx6 = x;
                                cy6 = y;
                                f = f - 1;
                            }
                        }
                    } // city 6 xy
                    else if (f == 10)
                    {
                        if (y != b2)
                        {
                            mcx1 = abs(x - cx6);
                            mcy1 = abs(y -
                                       cy6);
                            if (mcx1 + mcy1 >= 3)
                            {
                                printf("%d.%d; ", x, y);
                                f = f - 1;
                                cx7 = x;
                                cy7 = y;
                            }
                        }
                    }
                }
            }
        } // city 7 xy
        if (f <= 9)
        {
            if (f >= 5)
            {
                if (x > 6)
                {
                    if (x < 10)
                    {
                        if (y > 7)
                        {
                            if (y < 15)
                            {
                                mcx1 = abs(x -
                                           cx7); // this suppose to be 4 contested cities
                                if (f == 9)
                                {
                                    mcy1 = abs(y - cy7);
                                    if (mcx1 + mcy1 >= 3)
                                    {
                                        printf("%d.%d;", x, y);
                                        cx8 = x;
                                        cy8 = y;
                                        f = f - 1;
                                    }
                                }
                                else if (f == 8)
                                {
                                    mcx1 = abs(x - cx8);
                                    mcy1 = abs(y - cy8);
                                    if (mcx1 + mcy1 >= 3)
                                    {
                                        printf("%d.%d; \n", x, y);
                                        cx9 = x;
                                        cy9 = y;
                                        f = f -
                                            1;
                                    }
                                }
                                else if (f == 7)
                                {
                                    mcx1 = abs(x - cx9);
                                    mcy1 = abs(y - cy9);
                                    if (x != cx8)
                                    {
                                        if (mcx1 + mcy1 >= 3)
                                        {
                                            printf("%d.%d;", x, y);
                                            cx10 = x;
                                            cy10 = y;
                                            f = f - 1;
                                        }
                                    }
                                }
                                else if (f == 6)
                                {
                                    mcx1 = abs(x - cx10);
                                    mcy1 = abs(y - cy10);
                                    if (x != cx9)
                                    {
                                        if (mcx1 + mcy1 >= 3)
                                        {
                                            printf("%d.%d;", x, y);
                                            cx11 = x;
                                            cy11 = y;
                                            f = f - 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (x > 1)
        {
            if (y < 20)
            {
                if (f <= 5)
                {
                    if (f >= 1)
                    { // base 3 cities (4) airport(1)
                        if (ma3 + mb3 == 3)
                        {
                            if (f == 5)
                            {
                                if (x != cx11)
                                {
                                    printf("%d.%d; ", x, y);
                                    f = f -
                                        1;
                                    cx12 = x;
                                    cy12 = y;
                                }
                            } // city12 xy
                            else if (f == 4)
                            {
                                if (mcx5 + mcy5 >= 3)
                                {
                                    printf("%d.%d; ", x, y);
                                    f = f -
                                        1;
                                    cx13 = x;
                                    cy13 = y;
                                }
                            } // city 13 xy
                            else if (f == 3)
                            {
                                mcx1 = abs(x - cx13);
                                mcy1 = abs(y - cy13);
                                if (mcx1 + mcy1 >= 3)
                                {
                                    printf("%d.%d; ", x, y);
                                    cx14 = x;
                                    cy14 = y;
                                    f = f - 1;
                                }
                            }
                        } // city 14 xy
                        else if (f == 2)
                        {
                            mcx1 = abs(x - cx14);
                            mcy1 = abs(y - cy14);
                            if (mcx1 + mcy1 >= 3)
                            {
                                printf("%d.%d; ", x, y);
                                cx15 = x;
                                cy15 = y;
                                f = f - 1;
                            }
                        }
                    } // city 15 xy;}}}}
                    if (ma3 + mb3 == 4)
                    {
                        if (f == 1)
                        {
                            if (x <= 7)
                            {
                                mcx1 = abs(x - cx15);
                                mcy1 = abs(y -
                                           cy15);
                                if (mcx1 + mcy1 > 2)
                                {
                                    printf("%d.%d; ", x, y);
                                    f = f - 1;
                                    cx16 = x;
                                    cy16 = y;
                                }
                            }
                        }
                    }
                }
            }
        } // airport xy
        if (x % 10 == 0)
        {
            y = y + 1;
            x = 0;
        }
    }
    y = 1;
    x = 0; // ready for another loop
    printf("\n Loop for actual map \n");
    for (int i = 1; i < 401; ++i)
    { // the result we need is from here
        x = x + 1;
        mx = abs(x - x1);
        my = y - y1;
        z = mx + my;
        r = random(1, 3);
        l = i % 20;
        if (x > 10)
        {
            r = 28;
        } // sea
        if (x == 11)
        {
            if (y == 2)
            {
                r = 42;
            }
        } // HQ just for the map can be uploaded
        if (x == 12)
        {
            if (y == 2)
            {
                r = 47;
            }
        }
        if (x == 1)
        {
            r = 28;
        } // sea
        if (y == 1)
        {
            r = 28;
        }
        if (y == 20)
        {
            r = 28;
        }
        if (x == a1)
        {
            if (y == b1)
            {
                r = 35;
            }
        } // base
        if (x == a2)
        {
            if (y == b2)
            {
                r = 35;
            }
        }
        if (x == a3)
        {
            if (y == b3)
            {
                r = 35;
            }
        }
        if (x == cx1)
        {
            if (y == cy1)
            {
                r = 34;
            }
        } // cities
        if (x == cx2)
        {
            if (y == cy2)
            {
                r = 34;
            }
        }
        if (x == cx3)
        {
            if (y == cy3)
            {
                r = 34;
            }
        }
        if (x == cx4)
        {
            if (y == cy4)
            {
                r = 34;
            }
        }
        if (x == cx5)
        {
            if (y == cy5)
            {
                r = 34;
            }
        }
        if (x == cx6)
        {
            if (y == cy6)
            {
                r = 34;
            }
        }
        if (x == cx7)
        {
            if (y == cy7)
            {
                r = 34;
            }
        }
        if (x == cx8)
        {
            if (y == cy8)
            {
                r = 34;
            }
        }
        if (x == cx9)
        {
            if (y == cy9)
            {
                r = 34;
            }
        }
        if (x == cx10)
        {
            if (y == cy10)
            {
                r = 34;
            }
        }
        if (x == cx11)
        {
            if (y == cy11)
            {
                r = 34;
            }
        }
        if (x == cx12)
        {
            if (y == cy12)
            {
                r = 34;
            }
        }
        if (x == cx13)
        {
            if (y == cy13)
            {
                r = 34;
            }
        }
        if (x == cx14)
        {
            if (y == cy14)
            {
                r = 34;
            }
        }
        if (x == cx15)
        {
            if (y == cy15)
            {
                r = 34;
            }
        }
        if (x == cx16)
        {
            if (y == cy16)
            {
                r = 36;
            }
        }
        if (r == 2)
        {
            r = random(2, 4);
            if (r >= 3)
            {
                r = 1;
            }
        } // clearing mountain
        else if (r == 3)
        {
            r = random(1, 3);
            if (r >= 2)
            {
                r = 3;
            }
        } // clearing forest
        if (x < 20)
        {
            printf("%d,", r);
        }
        else if (x == 20)
        {
            printf("%d", r);
        }
        if (l == 0)
        {
            printf("\n");
            y = y + 1;
            x = 0;
        }
    }
    return 0;
}
