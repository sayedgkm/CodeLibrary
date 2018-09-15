///Find maximum of unimodal function f() within [left, right]
///To find the minimum, revert the if/else statement or revert the comparison.
double trinarySearch(double b , double e) {
    while(e-b>eps) {
        double m1=b+(e-b)/3.0;  /// m1=(b*2+e)/3.0;
        double m2=b+2.0*(e-b)/3.0;  ///m2=(b+e*2)/3.0;
        if(fun(m1)<=fun(m2)+eps)
            b=m1;
        else e=m2;
    }
    return b;
}
while(lo < hi) {      /// ternery search on integer
    int mid = (lo + hi) >> 1;
    if(f(mid) > f(mid+1)) {
        hi = mid;
    } else {
        lo = mid+1;
    }
}
/// NOTES: Given two points A(x1,y1) and B(x2,y2).A particle goes from point A to B in 1 sec.
/// now what is the new position of that particle after t sec if it starts moving from point A to point B?
///Let's A to B direction vector is AB(X,Y), where X=x2-x1 and Y=y2-y1
/// After t sec new position px= x1+(X*t) ans py=y1+Y*t;


