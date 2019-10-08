#include <stdio.h>

int main(void) {
	int t,m,x,y,i,n=0,z=1,tot=0,j,min;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d %d %d",&m,&x,&y);
	    int a[m];
	    for(i=0;i<m;i++){
	        scanf("%d",&a[i]);
	    }

	    for(i=0;i<m;i++){
	        for(j=i+1;j<m;j++){
	            if(a[i]>a[j]){
	                min=a[j];
	                a[j]=a[i];
	                a[i]=min;
	            }
	        }
	    }

	    if(a[0]>x*y)
	     tot+=a[0]-x*y-1;

	    for(i=1;i<m;i++){
	      if(a[i]-a[i-1]>(2*x*y)){
	          tot+=a[i]-a[i-1]-(2*x*y)-1;
	      }

	    }
	    if(150>a[m-1]+(x*y)){
        tot+=+150-a[m-1]-(x*y);
      }
	    printf("%d\n",tot);
	    tot=0;
	}
	return 0;
}
