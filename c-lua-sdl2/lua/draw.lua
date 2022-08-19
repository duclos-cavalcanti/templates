function draw(time_diff, x, y)
    local w,h
    local radius = 20
    for w=0,radius*2,1 do
        for h=0,radius*2,1 do
            dx = radius - w
            dy = radius - h
            if dx*dx + dy*dy <= radius*radius then
                drawpoint(x + dx, y + dy)
            end
        end
    end
end
