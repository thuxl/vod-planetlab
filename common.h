#ifndef  COMMON_H
#define  COMMON_H


#define    MAXLINE        1024*1024
#define    REC_FILENAME        "received_data"
#define    SENDER_FILENAME     "data_to_send"
#define    TRANS_DATA_PORT     1500


#define    NUM_OF_PEERS			400
#define    PEERS_ON_NODE        200
#define    NUM_OF_T				10
#define    NUM_OF_MOVIES		30	
#define    NUM_OF_SEGS_EACH_MOVIE		1	
#define    NUM_OF_SEGS			30
#define    INIT_CACHE_EXP       0.1
//in kb
#define    MEM_OF_SEG			4000

//#define MY_PRINT(msg)
#define MY_PRINT(msg)              \
  do                                    \
    {                                   \
	  std::cout << "["<<node::myid <<"] "<<time(NULL) - node::start_t << " "<< msg <<"("<<__FILE__<<","<<__FUNCTION__ <<","<<__LINE__<<")"<< std::endl; \
	}                                   \
  while (false)




#define    TRANS_CONTROL_PORT0     3500
#define    TRANS_CONTROL_PORT1     3501
#define    TRANS_CONTROL_PORT2     3502
#define    TRANS_CONTROL_PORT3     3503
#define    TRANS_CONTROL_PORT4     3504
#define    TRANS_CONTROL_PORT5     3505
#define    TRANS_CONTROL_PORT5     3505
#define    TRANS_CONTROL_PORT6     3506
#define    TRANS_CONTROL_PORT7     3507
#define    TRANS_CONTROL_PORT8     3508
#define    TRANS_CONTROL_PORT9     3509

#define    TRANS_CONTROL_PORT10     3510
#define    TRANS_CONTROL_PORT11     3511
#define    TRANS_CONTROL_PORT12     3512
#define    TRANS_CONTROL_PORT13     3513
#define    TRANS_CONTROL_PORT14     3514
#define    TRANS_CONTROL_PORT15     3515
#define    TRANS_CONTROL_PORT15     3515
#define    TRANS_CONTROL_PORT16     3516
#define    TRANS_CONTROL_PORT17     3517
#define    TRANS_CONTROL_PORT18     3518
#define    TRANS_CONTROL_PORT19     3519

#define    TRANS_CONTROL_PORT20     3520
#define    TRANS_CONTROL_PORT21     3521
#define    TRANS_CONTROL_PORT22     3522
#define    TRANS_CONTROL_PORT23     3523
#define    TRANS_CONTROL_PORT24     3524
#define    TRANS_CONTROL_PORT25     3525
#define    TRANS_CONTROL_PORT25     3525
#define    TRANS_CONTROL_PORT26     3526
#define    TRANS_CONTROL_PORT27     3527
#define    TRANS_CONTROL_PORT28     3528
#define    TRANS_CONTROL_PORT29     3529

#define    TRANS_CONTROL_PORT30     3530
#define    TRANS_CONTROL_PORT31     3531
#define    TRANS_CONTROL_PORT32     3532
#define    TRANS_CONTROL_PORT33     3533
#define    TRANS_CONTROL_PORT34     3534
#define    TRANS_CONTROL_PORT35     3535
#define    TRANS_CONTROL_PORT36     3536
#define    TRANS_CONTROL_PORT37     3537
#define    TRANS_CONTROL_PORT38     3538
#define    TRANS_CONTROL_PORT39     3539

#define    TRANS_CONTROL_PORT40     3540
#define    TRANS_CONTROL_PORT41     3541
#define    TRANS_CONTROL_PORT42     3542
#define    TRANS_CONTROL_PORT43     3543
#define    TRANS_CONTROL_PORT44     3544
#define    TRANS_CONTROL_PORT45     3545
#define    TRANS_CONTROL_PORT45     3545
#define    TRANS_CONTROL_PORT46     3546
#define    TRANS_CONTROL_PORT47     3547
#define    TRANS_CONTROL_PORT48     3548
#define    TRANS_CONTROL_PORT49     3549

#define    TRANS_CONTROL_PORT50     3550
#define    TRANS_CONTROL_PORT51     3551
#define    TRANS_CONTROL_PORT52     3552
#define    TRANS_CONTROL_PORT53     3553
#define    TRANS_CONTROL_PORT54     3554
#define    TRANS_CONTROL_PORT55     3555
#define    TRANS_CONTROL_PORT55     3555
#define    TRANS_CONTROL_PORT56     3556
#define    TRANS_CONTROL_PORT57     3557
#define    TRANS_CONTROL_PORT58     3558
#define    TRANS_CONTROL_PORT59     3559

#define    TRANS_CONTROL_PORT60     3560
#define    TRANS_CONTROL_PORT61     3561
#define    TRANS_CONTROL_PORT62     3562
#define    TRANS_CONTROL_PORT63     3563
#define    TRANS_CONTROL_PORT64     3564
#define    TRANS_CONTROL_PORT65     3565
#define    TRANS_CONTROL_PORT65     3565
#define    TRANS_CONTROL_PORT66     3566
#define    TRANS_CONTROL_PORT67     3567
#define    TRANS_CONTROL_PORT68     3568
#define    TRANS_CONTROL_PORT69     3569

#define    TRANS_CONTROL_PORT70     3570
#define    TRANS_CONTROL_PORT71     3571
#define    TRANS_CONTROL_PORT72     3572
#define    TRANS_CONTROL_PORT73     3573
#define    TRANS_CONTROL_PORT74     3574
#define    TRANS_CONTROL_PORT75     3575
#define    TRANS_CONTROL_PORT75     3575
#define    TRANS_CONTROL_PORT76     3576
#define    TRANS_CONTROL_PORT77     3577
#define    TRANS_CONTROL_PORT78     3578
#define    TRANS_CONTROL_PORT79     3579

#define    TRANS_CONTROL_PORT80     3580
#define    TRANS_CONTROL_PORT81     3581
#define    TRANS_CONTROL_PORT82     3582
#define    TRANS_CONTROL_PORT83     3583
#define    TRANS_CONTROL_PORT84     3584
#define    TRANS_CONTROL_PORT85     3585
#define    TRANS_CONTROL_PORT85     3585
#define    TRANS_CONTROL_PORT86     3586
#define    TRANS_CONTROL_PORT87     3587
#define    TRANS_CONTROL_PORT88     3588
#define    TRANS_CONTROL_PORT89     3589

#define    TRANS_CONTROL_PORT90     3590
#define    TRANS_CONTROL_PORT91     3591
#define    TRANS_CONTROL_PORT92     3592
#define    TRANS_CONTROL_PORT93     3593
#define    TRANS_CONTROL_PORT94     3594
#define    TRANS_CONTROL_PORT95     3595
#define    TRANS_CONTROL_PORT95     3595
#define    TRANS_CONTROL_PORT96     3596
#define    TRANS_CONTROL_PORT97     3597
#define    TRANS_CONTROL_PORT98     3598
#define    TRANS_CONTROL_PORT99     3599









#define    TRANS_CONTROL_PORT100     3600
#define    TRANS_CONTROL_PORT101     3601
#define    TRANS_CONTROL_PORT102     3602
#define    TRANS_CONTROL_PORT103     3603
#define    TRANS_CONTROL_PORT104     3604
#define    TRANS_CONTROL_PORT105     3605
#define    TRANS_CONTROL_PORT105     3605
#define    TRANS_CONTROL_PORT106     3606
#define    TRANS_CONTROL_PORT107     3607
#define    TRANS_CONTROL_PORT108     3608
#define    TRANS_CONTROL_PORT109     3609

#define    TRANS_CONTROL_PORT110     3610
#define    TRANS_CONTROL_PORT111     3611
#define    TRANS_CONTROL_PORT112     3612
#define    TRANS_CONTROL_PORT113     3613
#define    TRANS_CONTROL_PORT114     3614
#define    TRANS_CONTROL_PORT115     3615
#define    TRANS_CONTROL_PORT115     3615
#define    TRANS_CONTROL_PORT116     3616
#define    TRANS_CONTROL_PORT117     3617
#define    TRANS_CONTROL_PORT118     3618
#define    TRANS_CONTROL_PORT119     3619

#define    TRANS_CONTROL_PORT120     3620
#define    TRANS_CONTROL_PORT121     3621
#define    TRANS_CONTROL_PORT122     3622
#define    TRANS_CONTROL_PORT123     3623
#define    TRANS_CONTROL_PORT124     3624
#define    TRANS_CONTROL_PORT125     3625
#define    TRANS_CONTROL_PORT125     3625
#define    TRANS_CONTROL_PORT126     3626
#define    TRANS_CONTROL_PORT127     3627
#define    TRANS_CONTROL_PORT128     3628
#define    TRANS_CONTROL_PORT129     3629

#define    TRANS_CONTROL_PORT130     3630
#define    TRANS_CONTROL_PORT131     3631
#define    TRANS_CONTROL_PORT132     3632
#define    TRANS_CONTROL_PORT133     3633
#define    TRANS_CONTROL_PORT134     3634
#define    TRANS_CONTROL_PORT135     3635
#define    TRANS_CONTROL_PORT136     3636
#define    TRANS_CONTROL_PORT137     3637
#define    TRANS_CONTROL_PORT138     3638
#define    TRANS_CONTROL_PORT139     3639

#define    TRANS_CONTROL_PORT140     3640
#define    TRANS_CONTROL_PORT141     3641
#define    TRANS_CONTROL_PORT142     3642
#define    TRANS_CONTROL_PORT143     3643
#define    TRANS_CONTROL_PORT144     3644
#define    TRANS_CONTROL_PORT145     3645
#define    TRANS_CONTROL_PORT145     3645
#define    TRANS_CONTROL_PORT146     3646
#define    TRANS_CONTROL_PORT147     3647
#define    TRANS_CONTROL_PORT148     3648
#define    TRANS_CONTROL_PORT149     3649

#define    TRANS_CONTROL_PORT150     3650
#define    TRANS_CONTROL_PORT151     3651
#define    TRANS_CONTROL_PORT152     3652
#define    TRANS_CONTROL_PORT153     3653
#define    TRANS_CONTROL_PORT154     3654
#define    TRANS_CONTROL_PORT155     3655
#define    TRANS_CONTROL_PORT155     3655
#define    TRANS_CONTROL_PORT156     3656
#define    TRANS_CONTROL_PORT157     3657
#define    TRANS_CONTROL_PORT158     3658
#define    TRANS_CONTROL_PORT159     3659

#define    TRANS_CONTROL_PORT160     3660
#define    TRANS_CONTROL_PORT161     3661
#define    TRANS_CONTROL_PORT162     3662
#define    TRANS_CONTROL_PORT163     3663
#define    TRANS_CONTROL_PORT164     3664
#define    TRANS_CONTROL_PORT165     3665
#define    TRANS_CONTROL_PORT165     3665
#define    TRANS_CONTROL_PORT166     3666
#define    TRANS_CONTROL_PORT167     3667
#define    TRANS_CONTROL_PORT168     3668
#define    TRANS_CONTROL_PORT169     3669

#define    TRANS_CONTROL_PORT170     3670
#define    TRANS_CONTROL_PORT171     3671
#define    TRANS_CONTROL_PORT172     3672
#define    TRANS_CONTROL_PORT173     3673
#define    TRANS_CONTROL_PORT174     3674
#define    TRANS_CONTROL_PORT175     3675
#define    TRANS_CONTROL_PORT175     3675
#define    TRANS_CONTROL_PORT176     3676
#define    TRANS_CONTROL_PORT177     3677
#define    TRANS_CONTROL_PORT178     3678
#define    TRANS_CONTROL_PORT179     3679

#define    TRANS_CONTROL_PORT180     3680
#define    TRANS_CONTROL_PORT181     3681
#define    TRANS_CONTROL_PORT182     3682
#define    TRANS_CONTROL_PORT183     3683
#define    TRANS_CONTROL_PORT184     3684
#define    TRANS_CONTROL_PORT185     3685
#define    TRANS_CONTROL_PORT185     3685
#define    TRANS_CONTROL_PORT186     3686
#define    TRANS_CONTROL_PORT187     3687
#define    TRANS_CONTROL_PORT188     3688
#define    TRANS_CONTROL_PORT189     3689

#define    TRANS_CONTROL_PORT190     3690
#define    TRANS_CONTROL_PORT191     3691
#define    TRANS_CONTROL_PORT192     3692
#define    TRANS_CONTROL_PORT193     3693
#define    TRANS_CONTROL_PORT194     3694
#define    TRANS_CONTROL_PORT195     3695
#define    TRANS_CONTROL_PORT195     3695
#define    TRANS_CONTROL_PORT196     3696
#define    TRANS_CONTROL_PORT197     3697
#define    TRANS_CONTROL_PORT198     3698
#define    TRANS_CONTROL_PORT199     3699




#endif
