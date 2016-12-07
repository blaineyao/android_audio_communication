package com.yaobin.audio_communication;

import android.media.AudioFormat;
import android.media.AudioRecord;
import android.media.MediaRecorder;

public class MessageRec {
	private final int recSampleRate = 8000;
	private final int recChannel = AudioFormat.CHANNEL_IN_MONO;  
	private final int recAudioFormat = AudioFormat.ENCODING_PCM_16BIT; 
	private final int audioSource = MediaRecorder.AudioSource.MIC;
	public final int minRecBufSize = AudioRecord.getMinBufferSize(recSampleRate, recChannel, recAudioFormat);
	AudioRecord audioRecord;//Â¼Òô
	RecordThread recThread;
	private boolean recordFlag = false;
	
	public MessageRec(){
		audioRecord = new AudioRecord(audioSource, recSampleRate, recChannel, recAudioFormat, minRecBufSize);
	}
	public void StartRecord(){
		recThread = new RecordThread(audioRecord, minRecBufSize);
		recordFlag = true;
		recThread.start();
	}
	public void StopRecord(){
		recordFlag = false; 
		recThread = null;
	}
	
	public class RecordThread extends Thread{
		private AudioRecord ar;
		private int bufSize;
		
		public RecordThread(AudioRecord audioRecord, int bufferSize){
			this.ar = audioRecord;
			this.bufSize = bufferSize;	
		}
		public void run(){
			try{
				WaveDecoder wavedecoder;
				wavedecoder=new WaveDecoder(bufSize);
				short[] buffer = new short[bufSize];
				ar.startRecording();
				while(recordFlag){
					int ret = ar.read(buffer, 0, bufSize);
					if(ret == AudioRecord.ERROR_BAD_VALUE){
						recordFlag = false;
					}
					else{
						short[] tmpBuf = new short[ret];
						System.arraycopy(buffer, 0, tmpBuf, 0, ret);
						//System.out.println("OK,");
						//wavedecoder.decoder(buffer,ret);//½âÂë
						//System.out.printf("%d,",ret);
						/*
						for(int i=0;i<ret;i++){							
							if(i%10==0)
							{
								System.out.println("\r\n");
							}
							System.out.printf("0x%x,",buffer[i]);

						}*/
					}
				}
				ar.stop();
				ar.release();
				wavedecoder=null;
			}
			catch (Exception e){
				System.out.println("Receive message Error");
			}
		}
	}
}
