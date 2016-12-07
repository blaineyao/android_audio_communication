package com.yaobin.audio_communication;

import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;

public class MessageOut {
	public static final int RATE=44100;//ÿ��������ĸ���44100 22050 11025
	public static final int bit_length=1102;//���ݵĳ���
	public static final int start_length=2205;//���ݵĳ���
	
	public static final  int pcm_bit=AudioFormat.ENCODING_PCM_8BIT;//8λPCM����   ENCODING_PCM_16BIT 16λPCM����
	public static final int channel=AudioFormat.CHANNEL_OUT_MONO;//������CHANNEL_OUT_MONO ˫����CHANNEL_OUT_STEREO
	public static final int minBuffersize=AudioTrack.getMinBufferSize(RATE, channel, pcm_bit);
	AudioTrack audioTrack;
	public void StartAudio(){
		audioTrack=new AudioTrack(AudioManager.STREAM_SYSTEM,
				RATE,//ÿ��������ĸ���
				channel,//������CHANNEL_OUT_MONO CHANNEL_OUT_STEREO
				pcm_bit,//8λPCM����   ENCODING_PCM_16BIT 16λPCM����
				minBuffersize,//buffer size
				AudioTrack.MODE_STREAM);//AudioTrack.MODE_STATIC
		if(audioTrack!=null){
			audioTrack.play();//������Ƶ�豸
			audioTrack.setStereoVolume(1, 0);//����������������
		}
	}
	public void StopAudio(){
		if(audioTrack!=null)//�ͷ���Դ
		{
			audioTrack.stop();
			audioTrack.release();		
			audioTrack=null;
		}		
	}
	public void SendData(byte byte_data){
		byte[] wave_bit=new byte[bit_length];
		byte[] wave_start=new byte[start_length];
		//System.out.println("0");//����
		wave_start=WaveEncoder.start_wave(wave_start);//��ʼλ,�ߵ�ƽ 
		//System.out.println("1");//����
		audioTrack.flush();//ˢ��
		audioTrack.write(wave_start, 0, start_length);
		for(int i=0;i<8;i++)//8λ����λ
		{
			if((byte_data&(1<<i))==0){
				wave_bit=WaveEncoder.bit_wave(wave_bit, 0);//�͵�ƽ
			}
			else{
				wave_bit=WaveEncoder.bit_wave(wave_bit, 1);//�ߵ�ƽ
			}
			audioTrack.flush();//ˢ��
			audioTrack.write(wave_bit, 0, bit_length);
		}
		wave_bit=WaveEncoder.bit_wave(wave_bit, 0);//�͵�ƽ 
		audioTrack.flush();//ˢ��
		audioTrack.write(wave_bit, 0, bit_length);
	}
}
