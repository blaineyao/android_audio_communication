package com.yaobin.audio_communication;

public class WaveDecoder {
	private int[]  prev_data;//����ǰһ�βɼ�������
	//private int prev_sign;//ǰһ�βɼ��������Ƿ�����ʼλ
	public WaveDecoder(int bufferSize){
		prev_data=new int[bufferSize];
	}
	private void calc1(short[] lin,int len) {//ȥ�뺯��
		short temp;
		for (int i = 0; i < len; i++) {
			temp = lin[i];
			lin[i] = (short)(temp>>2);
		}
	}
	private int[] convert_wave(short[] wave,int len){//������ת��Ϊ1 0 -1
		int temp[]=new int[len];
		for(int i=0;i<len;i++){
			if(wave[i]>(short)0x100&&wave[i]<(short)0x7fff)
				temp[i]=1;
			else if(wave[i]>(short)0x8000&&wave[i]<(short)0xffff)
				temp[i]=0;
			else temp[i]=-1;
		}
		return temp;
	} 
	/*
	private int search_data(int []data,int len){//Ѱ����Ϣ
		for(int i=0;i<len;i++){
			
		}
	}
	*/
	public void decoder(short[] wave,int len) {
		int []now_data=new int[len];
		calc1(wave,len);//ȥ������
		now_data=convert_wave(wave,len);
		int[] temp_data=new int[2*len];
		System.arraycopy(prev_data, 0, temp_data, 0,len);
		System.arraycopy(now_data, 0, temp_data, len,len);
		//search_data(temp_data,2*len);
		//for(int i=0;i<len;i++){
		//	if(i%10==0)System.out.println("\r\n");
		//	System.out.printf("0x%x,",wave[i]);			
		//}
		//for(int i=0;i<len;i++){
			//if(i%10==0)System.out.println("\r\n");
			//System.out.printf("%d,",now_data[i]);	
		//	if(now_data[i]>0)System.out.printf("\r\n%d,",now_data[i]);
		//}
		//System.out.println("\r\n");
		System.arraycopy(now_data, 0, prev_data, 0,len);
	}
}
