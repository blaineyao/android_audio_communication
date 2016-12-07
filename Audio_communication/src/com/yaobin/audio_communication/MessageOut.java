package com.yaobin.audio_communication;

import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;

public class MessageOut {
	public static final int RATE=44100;//每秒钟输出的个数44100 22050 11025
	public static final int bit_length=1102;//数据的长度
	public static final int start_length=2205;//数据的长度
	
	public static final  int pcm_bit=AudioFormat.ENCODING_PCM_8BIT;//8位PCM编码   ENCODING_PCM_16BIT 16位PCM编码
	public static final int channel=AudioFormat.CHANNEL_OUT_MONO;//单声道CHANNEL_OUT_MONO 双声道CHANNEL_OUT_STEREO
	public static final int minBuffersize=AudioTrack.getMinBufferSize(RATE, channel, pcm_bit);
	AudioTrack audioTrack;
	public void StartAudio(){
		audioTrack=new AudioTrack(AudioManager.STREAM_SYSTEM,
				RATE,//每秒钟输出的个数
				channel,//单声道CHANNEL_OUT_MONO CHANNEL_OUT_STEREO
				pcm_bit,//8位PCM编码   ENCODING_PCM_16BIT 16位PCM编码
				minBuffersize,//buffer size
				AudioTrack.MODE_STREAM);//AudioTrack.MODE_STATIC
		if(audioTrack!=null){
			audioTrack.play();//启动音频设备
			audioTrack.setStereoVolume(1, 0);//设置左右声道音量
		}
	}
	public void StopAudio(){
		if(audioTrack!=null)//释放资源
		{
			audioTrack.stop();
			audioTrack.release();		
			audioTrack=null;
		}		
	}
	public void SendData(byte byte_data){
		byte[] wave_bit=new byte[bit_length];
		byte[] wave_start=new byte[start_length];
		//System.out.println("0");//调试
		wave_start=WaveEncoder.start_wave(wave_start);//起始位,高电平 
		//System.out.println("1");//调试
		audioTrack.flush();//刷新
		audioTrack.write(wave_start, 0, start_length);
		for(int i=0;i<8;i++)//8位数据位
		{
			if((byte_data&(1<<i))==0){
				wave_bit=WaveEncoder.bit_wave(wave_bit, 0);//低电平
			}
			else{
				wave_bit=WaveEncoder.bit_wave(wave_bit, 1);//高电平
			}
			audioTrack.flush();//刷新
			audioTrack.write(wave_bit, 0, bit_length);
		}
		wave_bit=WaveEncoder.bit_wave(wave_bit, 0);//低电平 
		audioTrack.flush();//刷新
		audioTrack.write(wave_bit, 0, bit_length);
	}
}
