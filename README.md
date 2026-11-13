# Keyboard-Substitution-Program
A custom Kerbal Space Program Controller made for the Hack Club Stardance event!

# Overview
This project aims to create a custom controller for the game Kerbal Space Program which allows complete control of the game without the keyboard, shooting for a more immersive experience in game. 
This repository contains all code files for each arduino board in the controller, files for all 3d printed parts, a list of components needed to purchase, and instructions for how to build your own!

<img width="1408" height="1008" alt="Screenshot 2026-06-04 054627" src="https://github.com/user-attachments/assets/091b7b62-f863-48ef-9968-fe734054d668" />
<img width="675" height="900" alt="image" src="https://github.com/user-attachments/assets/bf1681bb-b1ae-4980-a104-f9a45fac045e" />


#Wiring Diagram
<img width="1366" height="768" alt="Screenshot from 2026-11-13 10-47-56" src="https://github.com/user-attachments/assets/e5ee4f50-5e68-4c51-8cdb-8ebed54cda8a" />

# Bill of Materials
<a href="https://docs.google.com/document/d/1xSK9mFhKcA0diG72t0lU2Y3A8E2znB5cS-Skv4FzVgU"> 3 Axis Joystick - x1 </a> <br>
<a href="https://reverb.com/item/90753295-behringer-b103-75mm-mixer-slider">Linear Slider - x1 </a> <br>
<a href="https://www.aliexpress.us/item/3256803930053813.html?UTABTest=aliabtest135178_42343&src=bing&exp_tag=pcgcp&albch=shopping&acnt=135095331&albcp=555220768&albag=1309519513086509&slnk=&trgt=pla-2333644710812054&plac=&crea=81845026508678&netw=s&device=c&mtctp=e&utm_source=Bing&utm_medium=shopping&utm_campaign=PA_Bing_US_Pmax_ALL_TROAS_AESupply_24.12.17&utm_content=US-ALL&utm_term=16+mm+latching+power+button&aff_fcid=d209b9aaac064402884c34b269a510b2-1779299352075-08793-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=d209b9aaac064402884c34b269a510b2-1779299352075-08793-UneMJZVf&terminal_id=4e56ba3f37b843f987be226e24637caa&OLP=1130900508_f_group2&o_s_id=1130900508&gatewayAdapt=glo2usa">BlueLatching Button - x3 </a> <br>
<a href="https://www.aliexpress.us/item/3256807106729164.html?spm=a2g0o.productlist.main.15.17572b4aEX2ck8&algo_pvid=82ffb7e9-2c26-466b-829f-812b25c871c0&algo_exp_id=82ffb7e9-2c26-466b-829f-812b25c871c0-14&pdp_ext_f=%7B%22order%22%3A%22283%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%213.91%213.41%21%21%2126.53%2123.14%21%402101e80317792986506223506ec726%2112000040091570281%21sea%21US%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3A27e2e220%3Bm03_new_user%3A-29895%3BpisId%3A5000000204886261&curPageLogUid=SXKblOUaLEMn&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005007293043916%7C_p_origin_prod%3A"> Green Keylock Switch - x3 </a>        <br>
<a href="https://www.amazon.com/dp/B095VWW4NT?_encoding=UTF8&th=1"> Keyboard Switches - x1 pack </a> <br>
<a href="https://www.amazon.com/APIELE-Mushroom-Momentary-Waterproof-Terminal/dp/B09KZ3TNQ6?dib=eyJ2IjoiMSJ9.ZjWu_RiVEx_8Io5ZZEkYuPT3FGBu5uQZXEPyAhzheiQ-MmkQrAVUmrkEG0ykCpbDG-jr9UQ8rnL1jWjBj1x63m586XfZDQL7UNK2y1rQLubJTP6v8QDAPPA8MlqjaYqU_M4TXom3mglk72WtuIzF63Zt_1r8wmBqthq8D_EXGmTueWaw3wh8vRgltvhs91eqvMEwxCtcqPP1LlGmEn5Taya60zqFuR4hNPDMzw9Kuhg.03PRP3scCzLIFheTb3uG6iwlKvMyBX9IS1aLT1koICs&dib_tag=se&keywords=22mm%2Bbutton&qid=1780343514&sr=8-7&th=1"> Big Button - x 2 </a> <br>
<a href="https://www.amazon.com/APIELE-Mushroom-Momentary-Waterproof-Terminal/dp/B09KZ3TNQ6?dib=eyJ2IjoiMSJ9.ZjWu_RiVEx_8Io5ZZEkYuPT3FGBu5uQZXEPyAhzheiQ-MmkQrAVUmrkEG0ykCpbDG-jr9UQ8rnL1jWjBj1x63m586XfZDQL7UNK2y1rQLubJTP6v8QDAPPA8MlqjaYqU_M4TXom3mglk72WtuIzF63Zt_1r8wmBqthq8D_EXGmTueWaw3wh8vRgltvhs91eqvMEwxCtcqPP1LlGmEn5Taya60zqFuR4hNPDMzw9Kuhg.03PRP3scCzLIFheTb3uG6iwlKvMyBX9IS1aLT1koICs&dib_tag=se&keywords=22mm%2Bbutton&qid=1780343514&sr=8-7&th=1"> Covered LED Switches - x2 </a> <br>
<a href="https://www.adafruit.com/product/2160"> 14 Segment Display - x9 </a> <br>
<a href="https://www.amazon.com/Plastic-Thermoplastic-Projects-Dual-Surface-Textured/dp/B0CMV289HW?crid=1OVB9FA8V64SJ&dib=eyJ2IjoiMSJ9.MzhH2LTOCmQxkJVOeoJbMpCxi5IoWGbAUa1BAOjjmbJ0IXJu9XiEsXqZ6CeQ4zA2OsSZBMnVVJiR1XeiGnfQHTmaQE61MRBAAIsAPrbFhaYJo-gDzl0jAExZhDOJ3XAGb2Yfat2dl6kQ-Wdr18BO_rpLFJQ9wqYeDAV03ypL23et0AHaoXfBHz2v_shU0Yrtd-xEeKRZRCv0844aAKRAME-WJ8k4fJA6LglMdw_ZQlE.vwO1xOG2V8NL3IsVu3zalaDTCw1QKU11aKHTrjM9VoE&dib_tag=se&keywords=abs+sheet+1%2F16&qid=1793503528&sprefix=abs+shee%2Caps%2C819&sr=8-4"> ABS Sheets - x4 </a> <br>
<a href="https://www.amazon.com/Rust-Oleum-331181-Painters-Touch-Ultra/dp/B0787D8PYT?crid=1DEZQA2URQKH0&dib=eyJ2IjoiMSJ9.UMN4WLDpk_yrqP99VKiBHUwP4s8PV_08RnAguz7mVVzjPhW6Fzx53qTwAhBWV5bipB0nPzQsg-q-1zqTLDOPjp0okcXDL2a1409UBRgzdYWuHVShX8cdOn5GCgnPJo05D_Cjr2iznzXgqdq3X-qtJ6mqHbSw6W6lCONEn9zRmMTjAJ5L_RmckFH8qYgsRznMxYGCHo3RJ3I5qmtl8dcIBqCoKyHUbTMLbqHKv59u6B6x1ZyshK1gwzoWOo78-7b4h_-3Pzp5KrJKyRjnCFxFKoZItHcEvX3fBUeyB1VBwmU.wHYJy2XIeiMBLL94D1d97LJn8hvdzfGDxv-e8J0x1AU&dib_tag=se&keywords=matte+white+spray+paint+for+plastic&qid=1793503584&sprefix=spray+paint+white+matte%2Caps%2C792&sr=8-5">Matte White Spraypaint - x1 </a> <br>
<a href="https://www.amazon.com/VGBUY-600pcs-Assortment-Printer-Stainless/dp/B0D1XJ766V?crid=322FX4F350JH6&dib=eyJ2IjoiMSJ9.cPekTjkEYdRojQiPp36UK4VinyBZzVGNtiiBTP5xpJ7S2xWalOf3EweyueF-HusgQzBwE0McYO20JO1wCSrbxpvblgY614GQT89YsFoXTNbplnaI9W9EoTMM8-cts_YzESRdSEaJj4Vkn_kfU6b76iV8ZnfsXCSdg_LyPqM9BWp8SxXX85vl5kWRpgR8wa2wmVznyh9VMZ1wRUHfptUaqf7wlQxInzueApNCuF5sVpM.TP4MREGoyjHpX8bTUHv1o6UQOFZh0TYCTBITcqUwCXg&dib_tag=se&keywords=m3+fastener+kit&qid=1793503763&sprefix=m3+fas%2Caps%2C150&sr=8-5">M3 Fasteners - x1 box </a> <br>
<a href="https://www.amazon.com/HANGLIFE-Heat-Set-Threaded-Printing-Components/dp/B0CS6VZYL8?crid=11D2II6JW4PSD&dib=eyJ2IjoiMSJ9.SJzCri0pQv_X1l8T5HZNmmXSjE4rDU9pxiBubuukBAA6yt3qVW3vAWEndIQqvGgidPRmUQdJ8Yrusb9mi79joj59HL0DmH7O0OfYDQdmnKNzUJWrbXJuOR7vAwyeDHNLu-FSQ7yQpf263ONRWf4SluA6IarHBhGwn5uTkswsPiw-bFk02G6Em6TQhnXrg4I51RvrsGHuKmP6XPz_jVi_p11fNULwBvN0cQM8vLCiB9o.guoMVFulOT9YHEv6dE8rSlbIxjhaOReZls-AyFikmIY&dib_tag=se&keywords=m3+heat+set+inserts&qid=1793503792&sprefix=m3+heat%2Caps%2C136&sr=8-3">M3 Heat Set Inserts - x1 </a> <br>
<a href="https://store.arduino.cc/products/uno-r4-minima">Arduino Uno R4 Minima - x2 </a> <br>
<a href="https://www.amazon.com/Splitter-Transfer-Multiport-Adapter-Compatible/dp/B0F5HSNDXF?dib=eyJ2IjoiMSJ9.P2offMzxr0dG7igxbJpYtuJYq7T8qYcTecyJNp2i-GhPCZ9wNfvuOYGOL_8UYYY-irkL8x1zj-A1BLmSB7mflTUktzpZsNTZt-lqsJkRRqnsa45PaYXjJOz2DCCRt3U6T8g45hLngXriSGUaGz4k1gf0h4X-cq2Whj0PW6RiKUFJm0I_ifaX_2Pj7cxWg3Fcj93S5YyAxZWQlgUM2BDEchsnFum2AhbJM0sM-mkS0xLbqv_NVa_GMaBg3OaBrUqKVNMfs0D2yUZzkFOc7DK-89JXrg8ECu1tJMz-5HLfMNY.r8ICm8029cJc4mwgcj4jXqfy0eT_E-YFu7G8xoN72xE&dib_tag=se&qid=1780621883&refinements=p_n_g-1003437938111%3A24222179011&s=pc&sr=1-17">USB C Hub x1 </a> <br>
<a href="https://www.amazon.com/Adapter-SOLMIMI-Double-Sided-High-Speed-Transmission/dp/B09J4DC92T?dib=eyJ2IjoiMSJ9.LkBS_V8C9LtT_oud-oYD3UKFvzqDSczGuyL7dXjGaiQbB62jUnn1NygrR0Mc9WaoQrFwhqgvYW2Tvzn0XdEhqN3xdoxVbzcE-I8wWQrrmvZCkHEnPgD6qH72JPv5eBW7rWE-p5wXpqxFksk0ngNxq7iCPOIsR5XpWcl4kRMx1_vqVSC5EJ_qArOaYtzItxa1CGtGthiTyAeIbs9_R-2K4ve2--G_JhscRlQcL63IANc.d0U3uLQV9wvpGEoTaIrXGgAfBRewtMwJZSxCwU5fNxE&dib_tag=se&keywords=usb-c+female+to+usb+male+adapter&qid=1780622384&sr=8-20">USB C to USB extension cable x1 </a> <br>
<a href="https://www.amazon.com/Anker-Charging-MacBook-Samsung-Nintendo/dp/B0CFZNZN25?dib=eyJ2IjoiMSJ9.ZV30rijpe9V9Yhr3P14bkMDK7z4moatF91q5555ZvFt7hCTLDHHMAdXB2OPKej1NRyfdRxcXW00ai_OHktF3PYfaiqi00Csyc-p1t9T_UR5tAp90-MfCf4cfd6ca8oV67ODJVook202M3T6CBkpIftxY7bMjEYSslHP1teC1AR_aLc8YX2QOjM-DWVy_MYRwPSj6pG-i4AmQr8Y7ndJDHbekb6X3yv7zbdTZ83Rt27I.PdwTXPMQrTWVfeo1PrzT9o1OpBQFZ9SIt8pL5wXF0PI&dib_tag=se&keywords=usb+c+to+usb+c+cable&qid=1793505979&sr=8-19">USB C to USB C cables -x1 </a> <br>
<a href="https://www.amazon.com/BOJACK-Values-Resistor-Resistors-Assortment/dp/B08FD1XVL6?crid=67F1JTS1ZAWF&dib=eyJ2IjoiMSJ9.QqtzmCG7CKt6OW1fHgTb20denXUkegR5Nbloon9rSneaxfDgibXvAtMfU3USecJBmH5N2yDhKItlJtXrLzsnKhcPqlNAPCG2_48tGc7eL39c-UK_fpbWO1XtAWzhdCXAOrpOHgM-lKtqpb8-RCfeNGM4p98kx_Iyp0fbd1eXG3cCIziHzyxUsVHU2P9LEhvKGu3tNaCF3ze4fKVJS5Y5iW8vma-Y75mNhLmFc811Xf8.1oNbZtdwKdBO-_sBDyTO6kxorcxnQ34h1FXnd8X6Ioc&dib_tag=se&keywords=resistors+assortment+kit&qid=1793506215&sprefix=resistors%2Caps%2C179&sr=8-3">Resistors -x1 pack </a> <br>
<a href="https://www.amazon.com/EEEEE-1N5819-Schottky-Electronic-Silicon/dp/B0FC2CWKPL?crid=3LJ96UB2U13W9&dib=eyJ2IjoiMSJ9.zdsFI874LMNy2ew0mZ6QnaU7SPMscwqVjzXv-YF0rzRDIXHzCsZKt2FTSXGH_sFQchTW2GG7-aUW4Vb08g5Ky_5jUbvgMJiLKJxy1VwPZJXsewANAV8dpA9izHCxFQdJAVaUK3XzB-Hqfwg2Mufh1yhaXVmQIGJWkTHTxhEY153JEZkBI2PrPwtg7gd-pmeNqOUCr80ICw-nSZjLZSR8bbfVbn-wAE1fc8Ee6Z4ug8M.FVHX6mLfdz0dTotB4oPxNhhWurtM9_JKDfkXmGAvbek&dib_tag=se&keywords=shotkey+diode&qid=1793506259&sprefix=shotkey+diode%2Caps%2C162&sr=8-4"> Diodes -x1 pack </a> <br>

# Specifics
 <a href="https://docs.google.com/document/d/1xSK9mFhKcA0diG72t0lU2Y3A8E2znB5cS-Skv4FzVgU">Parts List</a> 
<a href="https://cad.onshape.com/documents/f623b2689f20fb0d288adf48/w/e5e7af8b431c1f25b27c2839/e/9daf789d907df18f4bb0781c">CAD Files (hosted on Onshape)</a>

This project is based around the Kerbal Simpit Revamped Mod for Kerbal Space Program 1 (the code might work for KSP 2 as well but I dont own a copy so I cant ensure it)

It is built off of 2 Arduino Uno R4 Minima boards, providing enough inputs and outputs to control:
 
  - Staging (with safety switch)
  - Abort (with safety switch)
  - Attitude control (including fine control)
  - Throttle & RCS
  - 1 lines of alphanumerical data output with several modes avalible to view on demand
    
The main body and frame of the controller is built from 3D printed PETG sections glued together, with hardware attached via m3 fasteners and heat set inserts.

All code is written in C++ and the PlatformIO extension in VScode is used to upload the code onto the Arduinos.

# Instructions

To build the top cover
1. Spraypaint one ABS Sheet white
2. Use a cnc router and the included top cover file to cut the holes
2a. If you do not have a cnc router, print out some to scale engineering drawing of the cover. Place them on the cover and mark all of the holes, then hand cut and sand to the proper dimention
3. 3D print the files for all of the key switch holders
4. Line up the key switch holders on the part and drill out the holes for the fasteners (this is done now to make sure holes line up with the actual parts even if they are printed or cut weird)
5. Insert the heat set inserts into the holes in the parts

To build the rest of the case
1. Take one ABS sheet and cut it into 4 pieces 16 in by 3 in
2. Cut 2 of those pieces down to 12in by 3 in
3. Cut a rectangular hole on one of the 12 inch pieces, roughly an inch long and .5 in tall (this is where the wires come into)
4. Glue the 4 sides vertically onto another piece of ABS
5. Take the leftovers from cutting down the side pieces and cut them into smaller chunks, about 1.5 inches by 1.5 inches
6. Glue 4 of these chunks into the top corners of the case, and glue the rest wherever elsew you would like along the top perimeter (these are where the top cover rests.

To wire everything
- Simply follow the wiring diagram included in the KiCAD files

To get the code working
- Comment or uncomment functions in the main() loop depending on whats connected to that specific arduino
i.e. The joystick and throttle are connected to one arduino, so comment everything except for the joystick and throttle handlers.
